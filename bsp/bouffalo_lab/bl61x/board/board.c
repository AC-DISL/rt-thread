/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023/03/15     flyingcys    first version
 */
#include <firmament.h>
#include <msh.h>
#include <rthw.h>
#include <rtthread.h>
#include <shell.h>

#include "board.h"
#include "default_config.h"
#include "driver/barometer/spl06.h"
#include "driver/gps/gps_ubx.h"
#include "driver/imu/bmi088.h"
#include "driver/mag/bmm150.h"
#include "drv_uart.h"
#include "drv_flash.h"
#include "drv_rtc.h"
#include "drv_pwm.h"
#include "drv_rc.h"
#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/console/console_config.h"
#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/mavproxy_config.h"
#include "module/pmu/power_manager.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/actuator_config.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/mission_data.h"
#include "module/sysio/pilot_cmd.h"
#include "module/sysio/pilot_cmd_config.h"
#include "module/task_manager/task_manager.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"
#include "module/workqueue/workqueue_manager.h"

#ifdef FMT_USING_SIH
#include "model/plant/plant_interface.h"
#endif

#define MATCH(a, b) (strcmp(a, b) == 0)
#define SYS_CONFIG_FILE "/sys/sysconfig.toml"
#define SYS_INIT_SCRIPT "/sys/init.sh"

extern const struct romfs_dirent romfs_root;

static const struct dfs_mount_tbl mnt_table[] = {
    {"filesystem", "/", "elm", 0, NULL},
    //{"mtdblk0", "/mnt/mtdblk0", "elm", 0, NULL},
    {NULL, "/mnt/romfs", "rom", 0, &romfs_root},
    {NULL} /* NULL indicate the end */
};

static toml_table_t *__toml_root_tab = NULL;

static void banner_item(const char *name, const char *content, char pad,
                        uint32_t len) {
  int pad_len;

  if (content == NULL) {
    content = "NULL";
  }

  pad_len = len - strlen(name) - strlen(content);

  if (pad_len < 1) {
    pad_len = 1;
  }
  // e.g, name..............content
  console_printf("%s", name);
  while (pad_len--) {
    console_write(&pad, 1);
  }

  console_printf("%s\n", content);
}

#define BANNER_ITEM_LEN 42
static void bsp_show_information(void) {
  char buffer[50];

  console_printf("\n");
  console_println("   _____                               __ ");
  console_println("  / __(_)_____ _  ___ ___ _  ___ ___  / /_");
  console_println(" / _// / __/  ' \\/ _ `/  ' \\/ -_) _ \\/ __/");
  console_println("/_/ /_/_/ /_/_/_/\\_,_/_/_/_/\\__/_//_/\\__/ ");

  sprintf(buffer, "FMT FW %s", FMT_VERSION);
  banner_item("Firmware", buffer, '.', BANNER_ITEM_LEN);
  sprintf(buffer, "RT-Thread v%ld.%ld.%ld", RT_VERSION, RT_SUBVERSION,
          RT_REVISION);
  banner_item("Kernel", buffer, '.', BANNER_ITEM_LEN);
  banner_item("RAM", buffer, '.', BANNER_ITEM_LEN);
  banner_item("Target", TARGET_NAME, '.', BANNER_ITEM_LEN);
  banner_item("Vehicle", STR(VEHICLE_TYPE), '.', BANNER_ITEM_LEN);
  banner_item("Airframe", STR(AIRFRAME), '.', BANNER_ITEM_LEN);
  banner_item("INS Model", ins_model_info.info, '.', BANNER_ITEM_LEN);
  banner_item("FMS Model", fms_model_info.info, '.', BANNER_ITEM_LEN);
  banner_item("Control Model", control_model_info.info, '.', BANNER_ITEM_LEN);
#ifdef FMT_USING_SIH
  banner_item("Plant Model", plant_model_info.info, '.', BANNER_ITEM_LEN);
#endif

  console_println("Task Initialize:");
  fmt_task_desc_t task_tab = get_task_table();
  for (uint32_t i = 0; i < get_task_num(); i++) {
    sprintf(buffer, "  %s", task_tab[i].name);
    /* task status must be okay to reach here */
    banner_item(buffer,
                get_task_status(task_tab[i].name) == TASK_READY ? "OK" : "Fail",
                '.', BANNER_ITEM_LEN);
  }
}

static fmt_err_t bsp_parse_toml_sysconfig(toml_table_t *root_tab) {
  fmt_err_t err = FMT_EOK;
  toml_table_t *sub_tab;
  const char *key;
  const char *raw;
  char *target;
  int i;

  if (root_tab == NULL) {
    return FMT_ERROR;
  }

  /* target should be defined and match with bsp */
  if ((raw = toml_raw_in(root_tab, "target")) != 0) {
    if (toml_rtos(raw, &target) != 0) {
      console_printf("Error: fail to parse type value\n");
      err = FMT_ERROR;
    }
    if (!MATCH(target, TARGET_NAME)) {
      /* check if target match */
      console_printf("Error: target name doesn't match\n");
      err = FMT_ERROR;
    }
    rt_free(target);
  } else {
    console_printf("Error: can not find target key\n");
    err = FMT_ERROR;
  }

  if (err == FMT_EOK) {
    /* traverse all sub-table */
    for (i = 0; 0 != (key = toml_key_in(root_tab, i)); i++) {
      /* handle all sub tables */
      if (0 != (sub_tab = toml_table_in(root_tab, key))) {
        if (MATCH(key, "console")) {
          err = console_toml_config(sub_tab);
        } else if (MATCH(key, "mavproxy")) {
          err = mavproxy_toml_config(sub_tab);
        } else if (MATCH(key, "pilot-cmd")) {
          err = pilot_cmd_toml_config(sub_tab);
        } else if (MATCH(key, "actuator")) {
          err = actuator_toml_config(sub_tab);
        } else {
          console_printf("unknown table: %s\n", key);
        }
        if (err != FMT_EOK) {
          console_printf("fail to parse %s\n", key);
        }
      }
    }
  }

  /* free toml root table */
  toml_free(root_tab);

  return err;
}

static void system_clock_init(void)
{
#if 1
    /* wifipll/audiopll */
    GLB_Power_On_XTAL_And_PLL_CLK(GLB_XTAL_40M, GLB_PLL_WIFIPLL | GLB_PLL_AUPLL);
    GLB_Set_MCU_System_CLK(GLB_MCU_SYS_CLK_TOP_WIFIPLL_320M);
#else
    GLB_Set_MCU_System_CLK(GLB_MCU_SYS_CLK_RC32M);
    GLB_Power_On_XTAL_And_PLL_CLK(GLB_XTAL_40M, GLB_PLL_WIFIPLL);
    GLB_Config_AUDIO_PLL_To_384M();
    GLB_Set_MCU_System_CLK(GLB_MCU_SYS_CLK_TOP_AUPLL_DIV1);
    GLB_Set_MCU_System_CLK_Div(0, 3);
#endif
    CPU_Set_MTimer_CLK(ENABLE, BL_MTIMER_SOURCE_CLOCK_MCU_XCLK, Clock_System_Clock_Get(BL_SYSTEM_CLOCK_XCLK) / 1000000 - 1);
}

static void peripheral_clock_init(void)
{
    PERIPHERAL_CLOCK_ADC_DAC_ENABLE();
    PERIPHERAL_CLOCK_SEC_ENABLE();
    PERIPHERAL_CLOCK_DMA0_ENABLE();
    PERIPHERAL_CLOCK_UART0_ENABLE();
    PERIPHERAL_CLOCK_UART1_ENABLE();
    PERIPHERAL_CLOCK_SPI0_ENABLE();
    PERIPHERAL_CLOCK_I2C0_ENABLE();
    PERIPHERAL_CLOCK_PWM0_ENABLE();
    PERIPHERAL_CLOCK_TIMER0_1_WDG_ENABLE();
    PERIPHERAL_CLOCK_IR_ENABLE();
    PERIPHERAL_CLOCK_I2S_ENABLE();
    PERIPHERAL_CLOCK_USB_ENABLE();
    PERIPHERAL_CLOCK_CAN_ENABLE();

    GLB_Set_UART_CLK(ENABLE, HBN_UART_CLK_XCLK, 0);
    GLB_Set_SPI_CLK(ENABLE, GLB_SPI_CLK_MCU_MUXPLL_160M, 0);
    GLB_Set_I2C_CLK(ENABLE, GLB_I2C_CLK_XCLK, 0);
    GLB_Set_ADC_CLK(ENABLE, GLB_ADC_CLK_XCLK, 1);
    GLB_Set_DIG_CLK_Sel(GLB_DIG_CLK_XCLK);
    GLB_Set_DIG_512K_CLK(ENABLE, ENABLE, 0x4E);
    GLB_Set_PWM1_IO_Sel(GLB_PWM1_IO_DIFF_END);
    GLB_Set_IR_CLK(ENABLE, GLB_IR_CLK_SRC_XCLK, 19);
    GLB_Set_CAM_CLK(ENABLE, GLB_CAM_CLK_WIFIPLL_96M, 3);

    GLB_Set_PKA_CLK_Sel(GLB_PKA_CLK_MCU_MUXPLL_160M);
#ifdef CONFIG_BSP_SDH_SDCARD
    PERIPHERAL_CLOCK_SDH_ENABLE();
    GLB_AHB_MCU_Software_Reset(GLB_AHB_MCU_SW_EXT_SDH);
#endif

    GLB_Set_USB_CLK_From_WIFIPLL(1);
    GLB_Swap_MCU_SPI_0_MOSI_With_MISO(0);
}

#ifdef BSP_USING_PSRAM
static void bflb_init_psram_gpio(void)
{
    struct bflb_device_s *gpio;

    gpio = bflb_device_get_by_name("gpio");
    for (uint8_t i = 0; i < 12; i++) {
        bflb_gpio_init(gpio, (41 + i), GPIO_INPUT | GPIO_FLOAT | GPIO_SMT_EN | GPIO_DRV_0);
    }
}

static void psram_winbond_default_init(void)
{
    PSRAM_Ctrl_Cfg_Type default_psram_ctrl_cfg = {
        .vendor = PSRAM_CTRL_VENDOR_WINBOND,
        .ioMode = PSRAM_CTRL_X8_MODE,
        .size = PSRAM_SIZE_4MB,
        .dqs_delay = 0xfff0,
    };

    PSRAM_Winbond_Cfg_Type default_winbond_cfg = {
        .rst = DISABLE,
        .clockType = PSRAM_CLOCK_DIFF,
        .inputPowerDownMode = DISABLE,
        .hybridSleepMode = DISABLE,
        .linear_dis = ENABLE,
        .PASR = PSRAM_PARTIAL_REFRESH_FULL,
        .disDeepPowerDownMode = ENABLE,
        .fixedLatency = DISABLE,
        .brustLen = PSRAM_WINBOND_BURST_LENGTH_64_BYTES,
        .brustType = PSRAM_WRAPPED_BURST,
        .latency = PSRAM_WINBOND_6_CLOCKS_LATENCY,
        .driveStrength = PSRAM_WINBOND_DRIVE_STRENGTH_35_OHMS_FOR_4M_115_OHMS_FOR_8M,
    };

    PSram_Ctrl_Init(PSRAM0_ID, &default_psram_ctrl_cfg);
    // PSram_Ctrl_Winbond_Reset(PSRAM0_ID);
    PSram_Ctrl_Winbond_Write_Reg(PSRAM0_ID, PSRAM_WINBOND_REG_CR0, &default_winbond_cfg);
}

static uint32_t board_psram_x8_init(void)
{
    uint16_t reg_read = 0;

    GLB_Set_PSRAMB_CLK_Sel(ENABLE, GLB_PSRAMB_EMI_WIFIPLL_320M, 0);

    bflb_init_psram_gpio();

    /* psram init*/
    psram_winbond_default_init();
    /* check psram work or not */
    PSram_Ctrl_Winbond_Read_Reg(PSRAM0_ID, PSRAM_WINBOND_REG_ID0, &reg_read);
    return reg_read;
}
#endif

/* This is the timer interrupt service routine. */
static void systick_isr(void)
{
    rt_tick_increase();
}

void bsp_initialize(void) {
  /* start recording boot log */
  FMT_CHECK(boot_log_init());
  rt_kprintf("boot_log_init compeleted\n");

  /* init uMCN */
  FMT_CHECK(mcn_init());
  rt_kprintf("mcn_init compeleted\n");

  /* create workqueue */
  FMT_CHECK(workqueue_manager_init());
  rt_kprintf("workqueue_manager_init compeleted\n");

  /* init storage devices */
#ifdef BSP_USING_ON_CHIP_FLASH
  rt_hw_on_chip_flash_init();
#endif
  /* init file system */
  FMT_CHECK(file_manager_init(mnt_table));

  /* init parameter system */
  FMT_CHECK(param_init());
  rt_kprintf("param_init compeleted\n");

  //     /* init usbd_cdc */
  //     RT_CHECK(drv_usb_cdc_init());

  //     /* adc driver init */
  //     RT_CHECK(drv_adc_init());

  //     RT_CHECK(drv_aw2023_init("i2c0_dev0"));

#if defined(FMT_USING_SIH) || defined(FMT_USING_HIL)
  FMT_CHECK(advertise_sensor_imu(0));
  FMT_CHECK(advertise_sensor_mag(0));
  FMT_CHECK(advertise_sensor_baro(0));
  FMT_CHECK(advertise_sensor_gps(0));
  //   FMT_CHECK(advertise_sensor_airspeed(0));
#else
  /* init onboard sensors */
  // RT_CHECK(drv_bmi088_init("spi0_dev1", "spi0_dev0", "gyro0", "accel0", 0));
  // RT_CHECK(drv_bmm150_init("spi0_dev2", "mag0"));
  // RT_CHECK(drv_spl06_init("spi0_dev3", "barometer"));
  // RT_CHECK(gps_ubx_init("serial1", "gps"));
  // rt_kprintf("gps_ubx_init compeleted\n");

  // /* register sensor to sensor hub */
  // FMT_CHECK(register_sensor_imu("gyro0", "accel0", 0));
  // // FMT_CHECK(register_sensor_imu("gyro1", "accel1", 1));
  // FMT_CHECK(register_sensor_mag("mag0", 0));
  // FMT_CHECK(register_sensor_barometer("barometer"));
  // FMT_CHECK(advertise_sensor_optflow(0));
  // FMT_CHECK(advertise_sensor_rangefinder(0));

#endif

  //     /* init finsh */
  finsh_system_init();
  rt_kprintf("finsh_system_init compeleted\n");
  /* Mount finsh to console after finsh system init */
  FMT_CHECK(console_enable_input());

  // #ifdef FMT_USING_UNIT_TEST
  //     utest_init();
  // #endif
}

void rt_hw_board_init(void)
{
    bflb_flash_init();

    system_clock_init();
    peripheral_clock_init();
    bflb_irq_initialize();

    bflb_mtimer_config(HW_MTIMER_CLOCK / RT_TICK_PER_SECOND, systick_isr);

#ifdef RT_USING_HEAP
    /* initialize memory system */
    rt_kprintf("RT_HW_HEAP_BEGIN:%x RT_HW_HEAP_END:%x size: %d\r\n", RT_HW_HEAP_BEGIN, RT_HW_HEAP_END, RT_HW_HEAP_END - RT_HW_HEAP_BEGIN);
    rt_system_heap_init(RT_HW_HEAP_BEGIN, RT_HW_HEAP_END);
#endif


    /* UART driver initialization is open by default */
#ifdef RT_USING_SERIAL
    rt_hw_uart_init(); // uart0 for console , uart1 for gps
#endif

#ifdef RT_USING_RTC
    rt_hw_rtc_init();
    
#endif

#ifdef RT_USING_SPI
    rt_hw_spi_init();
#endif

#ifdef BSP_USING_PSRAM
    board_psram_x8_init();
    Tzc_Sec_PSRAMB_Access_Release();
#endif

    /* Set the shell console output device */
#if defined(RT_USING_CONSOLE) && defined(RT_USING_DEVICE)
    FMT_CHECK(console_init());
#endif

#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif

    rt_hw_pwm_init();

    drv_rc_init();
}

void bsp_post_initialize(void) {
  /* toml system configure */
  __toml_root_tab = toml_parse_config_file(SYS_CONFIG_FILE);
  if (!__toml_root_tab) {
    /* use default system configuration */
    __toml_root_tab = toml_parse_config_string(default_conf);
  }
  FMT_CHECK(bsp_parse_toml_sysconfig(__toml_root_tab));

  // /* init rc */
  FMT_CHECK(pilot_cmd_init());

  // /* init gcs */
  FMT_CHECK(gcs_cmd_init());

  // /* init auto command */
  //FMT_CHECK(auto_cmd_init());

  // /* init mission data */
  // FMT_CHECK(mission_data_init());

  // /* init actuator */
  FMT_CHECK(actuator_init());

  // /* start device message queue work */
  // FMT_CHECK(devmq_start_work());

  // /* initialize power management unit */
  // FMT_CHECK(pmu_init());

  /* init led control */
  //   FMT_CHECK(led_control_init());

  /* show system information */
  bsp_show_information();

  /* execute init script */
  msh_exec_script(SYS_INIT_SCRIPT, strlen(SYS_INIT_SCRIPT));

  /* dump boot log to file */
  boot_log_dump();
}

void rt_hw_cpu_reset(void)
{
    GLB_SW_POR_Reset();
}
MSH_CMD_EXPORT_ALIAS(rt_hw_cpu_reset, reboot, reset machine);
