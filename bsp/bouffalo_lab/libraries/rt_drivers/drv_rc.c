/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <rtdevice.h>
#include <rthw.h>
#include <rtthread.h>

#include "bflb_gpio.h"
#include "bflb_timer.h"
#include "bflb_dma.h"
#include "bflb_uart.h"
#include "hal/rc/ppm.h"
#include "hal/rc/sbus.h"
#include "hal/rc/rc.h"

#ifndef min // mod by prife
#define min(x, y) (x < y ? x : y)
#endif

/* capture accuracy is 0.001ms */
#define PPM_DECODER_FREQUENCY 1000000

#define HWTIMER_DEV_NAME "timer0" /* 定时器名称 */

/* default config for rc device */
#define RC_CONFIG_DEFAULT                                                      \
  {                                                                            \
    RC_PROTOCOL_PPM, /* auto */                                                \
        4,           /* 4 channel */                                           \
        0.05f,       /* sample time */                                         \
        1000,        /* minimal 1000us */                                      \
        2000,        /* maximal 2000us */                                      \
  }

#define PPM_RECV GPIO_PIN_10
#define PPM_COPY GPIO_PIN_11

static ppm_decoder_t ppm_decoder;
struct bflb_device_s *timer0;
struct bflb_device_s *gpio;

static sbus_decoder_t sbus_decoder;
struct bflb_device_s *sbus_uart;
struct bflb_device_s *dma_uart0_rx;

static ATTR_NOCACHE_NOINIT_RAM_SECTION uint8_t sbus_receive_buffer[25] = { 0 };

void gpio_isr(int irq, void *arg) {

  rt_interrupt_enter();

  uint32_t ic_val = bflb_timer_capture_get_pulsewidth(timer0);

  bool intstatus = bflb_gpio_get_intstatus(gpio, PPM_COPY);
  if (intstatus) {
    bflb_gpio_int_clear(gpio, PPM_COPY);
    ppm_update(&ppm_decoder, ic_val); // PPM信号捕获
  }

  rt_interrupt_leave();
}

void dma_uart0_rx_isr(void *arg)
{ 
    /* check frame format */
    if((sbus_receive_buffer[0] == 0x0F) && (sbus_receive_buffer[24] == 0x00)) {

        sbus_input(&sbus_decoder, sbus_receive_buffer, 25);

        if (!sbus_islock(&sbus_decoder)) {
            sbus_update(&sbus_decoder);
        }
    } 
}

//定时器用于记录中断触发的时间戳，配置输入捕获通道用于触发中断
static rt_err_t ppm_lowlevel_init(void) {

  //分一路PPM信号至GPIO11，用于产生上升沿中断
  gpio = bflb_device_get_by_name("gpio");
  bflb_gpio_init(gpio, PPM_COPY, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);

  bflb_gpio_int_init(gpio, PPM_COPY,
                     GPIO_INT_TRIG_MODE_SYNC_RISING_EDGE); //上升沿触发
  bflb_gpio_int_mask(gpio, PPM_COPY, false);

  bflb_irq_attach(gpio->irq_num, gpio_isr, gpio);
  bflb_irq_enable(gpio->irq_num);

  // timer configurations
  struct bflb_timer_config_s cfg0;
  cfg0.counter_mode = TIMER_COUNTER_MODE_UP; /* preload when match occur */
  cfg0.clock_source = TIMER_CLKSRC_XTAL;          // 40M
  cfg0.clock_div = 39; /* for bl616/bl808/bl606p is 39, for bl702 is 31 */
  cfg0.trigger_comp_id = TIMER_COMP_ID_0;
  cfg0.comp0_val = 0xFFFFFFFF;   /* match value 0  */
  cfg0.comp1_val = 0xFFFFFFFF; /* match value 1 */
  cfg0.comp2_val = 0xFFFFFFFF; /* match value 2 */
  cfg0.preload_val = 0;     /* preload value */

  timer0 = bflb_device_get_by_name("timer0");
  bflb_timer_init(timer0, &cfg0);

  struct bflb_timer_capture_config_s timer0_tp_config;
  timer0_tp_config.pin = PPM_RECV;
  timer0_tp_config.polarity = TIMER_CAPTURE_POLARITY_NEGATIVE;// low level capture
  bflb_timer_capture_init(timer0, &timer0_tp_config);

  bflb_timer_start(timer0);

  return RT_EOK;
}

static rt_err_t sbus_lowlevel_init(void)
{
    /* config uart0 */
    gpio = bflb_device_get_by_name("gpio");
    bflb_gpio_uart_init(gpio, GPIO_PIN_22, GPIO_UART_FUNC_UART0_RX);

    sbus_uart = bflb_device_get_by_name("uart0");

    /* 100000bps, even parity, two stop bits, sbus special configure */
    struct bflb_uart_config_s cfg;
    cfg.baudrate = 100000;
    cfg.data_bits = UART_DATA_BITS_8;
    cfg.stop_bits = UART_STOP_BITS_2;
    cfg.parity = UART_PARITY_EVEN;
    cfg.flow_ctrl = 0;
    cfg.rx_fifo_threshold = 24;
    bflb_uart_init(sbus_uart, &cfg);
    bflb_uart_link_rxdma(sbus_uart, true);

    /* config DMA uart0 rx */
    dma_uart0_rx = bflb_device_get_by_name("dma0_ch0");

    struct bflb_dma_channel_config_s rxconfig;
    rxconfig.direction = DMA_PERIPH_TO_MEMORY;
    rxconfig.src_req = DMA_REQUEST_UART0_RX;
    rxconfig.dst_req = DMA_REQUEST_NONE;
    rxconfig.src_addr_inc = DMA_ADDR_INCREMENT_DISABLE;
    rxconfig.dst_addr_inc = DMA_ADDR_INCREMENT_ENABLE;
    rxconfig.src_burst_count = DMA_BURST_INCR1;
    rxconfig.dst_burst_count = DMA_BURST_INCR1;
    rxconfig.src_width = DMA_DATA_WIDTH_8BIT;
    rxconfig.dst_width = DMA_DATA_WIDTH_8BIT;

    bflb_dma_channel_init(dma_uart0_rx, &rxconfig);
    bflb_dma_channel_irq_attach(dma_uart0_rx, dma_uart0_rx_isr, NULL);

    struct bflb_dma_channel_lli_pool_s rx_llipool[20];
    struct bflb_dma_channel_lli_transfer_s rx_transfers[1];

    rx_transfers[0].src_addr = (uint32_t)DMA_ADDR_UART0_RDR;
    rx_transfers[0].dst_addr = (uint32_t)sbus_receive_buffer;
    rx_transfers[0].nbytes = 25;

    int used_count = bflb_dma_channel_lli_reload(dma_uart0_rx, rx_llipool, 20, rx_transfers, 1);
    bflb_dma_channel_lli_link_head(dma_uart0_rx, rx_llipool, used_count);
    bflb_dma_channel_start(dma_uart0_rx);

    return RT_EOK;
}

static rt_err_t rc_control(rc_dev_t rc, int cmd, void *arg) {
  switch (cmd) {
  case RC_CMD_CHECK_UPDATE: {
      uint8_t updated = 0;

      if (rc->config.protocol == RC_PROTOCOL_SBUS) {
          updated = sbus_data_ready(&sbus_decoder);
      } else if (rc->config.protocol == RC_PROTOCOL_PPM) {
          updated = ppm_data_ready(&ppm_decoder);
      }

      *(uint8_t *)arg = updated;
  } break;

  default:
    break;
  }

  return RT_EOK;
}

static rt_uint16_t rc_read(rc_dev_t rc, rt_uint16_t chan_mask,
                           rt_uint16_t *chan_val) {
  uint16_t *index = chan_val;
  rt_uint16_t rb = 0;

    if (rc->config.protocol == RC_PROTOCOL_SBUS) {
        if (sbus_data_ready(&sbus_decoder) == 0) {
            /* no data received, just return */
            return 0;
        }

        sbus_lock(&sbus_decoder);

        for (uint8_t i = 0; i < min(rc->config.channel_num, sbus_decoder.rc_count); i++) {
            *(index++) = sbus_decoder.sbus_val[i];
            rb += 2;
        }
        
        sbus_data_clear(&sbus_decoder);

        sbus_unlock(&sbus_decoder);
    } else if (rc->config.protocol == RC_PROTOCOL_PPM) {
        if (ppm_data_ready(&ppm_decoder) == 0) {
            /* no data received, just return */
            return 0;
        }

        ppm_lock(&ppm_decoder);

        for (uint8_t i = 0; i < min(rc->config.channel_num, ppm_decoder.total_chan); i++) {
            if (chan_mask & (1 << i)) {
                *(index++) = ppm_decoder.ppm_val[i];
                rb += 2;
            }
        }
        ppm_data_clear(&ppm_decoder);

        ppm_unlock(&ppm_decoder);
    }

  return rb;
}

const static struct rc_ops rc_ops = {
    .rc_config = NULL,
    .rc_control = rc_control,
    .rc_read = rc_read,
};

static struct rc_device rc_dev = {
    .config = RC_CONFIG_DEFAULT,
    .ops = &rc_ops,
};

rt_err_t drv_rc_init(void) {
  /* init ppm driver */
  RT_TRY(ppm_lowlevel_init());
  /* init ppm decoder */
  RT_TRY(ppm_decoder_init(&ppm_decoder, PPM_DECODER_FREQUENCY));

  RT_TRY(sbus_lowlevel_init());
  RT_TRY(sbus_decoder_init(&sbus_decoder));

  RT_CHECK(hal_rc_register(&rc_dev, "rc", RT_DEVICE_FLAG_RDWR, NULL));

  return RT_EOK;
}