/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date             Author           Notes
 * 2023-03-12       wcx1024979076    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_pwm.h"
#include "bflb_mtimer.h"

#define DBG_LEVEL DBG_LOG
#include <rtdbg.h>
#define LOG_TAG "DRV.PWM"
#include "hal/actuator/actuator.h"

#ifdef BSP_USING_PWM

#define PWM_DEFAULT_FREQUENCY 500

static uint32_t __pwm_freq = PWM_DEFAULT_FREQUENCY;
static float __pwm_dc[PWM_V2_CH_MAX];

static struct bflb_pwm_v2_config_s cfg;

struct bflb_pwm_v2_channel_config_s ch_cfg[PWM_V2_CH_MAX] = {
    {
        .positive_polarity = PWM_POLARITY_ACTIVE_LOW,
        .negative_polarity = PWM_POLARITY_ACTIVE_LOW,
        .positive_stop_state = PWM_STATE_INACTIVE,
        .negative_stop_state = PWM_STATE_ACTIVE,
        .positive_brake_state = PWM_STATE_INACTIVE,
        .negative_brake_state = PWM_STATE_ACTIVE,
        .dead_time = 0,
    },
    {
        .positive_polarity = PWM_POLARITY_ACTIVE_LOW,
        .negative_polarity = PWM_POLARITY_ACTIVE_LOW,
        .positive_stop_state = PWM_STATE_ACTIVE,
        .negative_stop_state = PWM_STATE_INACTIVE,
        .positive_brake_state = PWM_STATE_ACTIVE,
        .negative_brake_state = PWM_STATE_ACTIVE,
        .dead_time = 0,
    },
    {
        .positive_polarity = PWM_POLARITY_ACTIVE_LOW,
        .negative_polarity = PWM_POLARITY_ACTIVE_LOW,
        .positive_stop_state = PWM_STATE_INACTIVE,
        .negative_stop_state = PWM_STATE_INACTIVE,
        .positive_brake_state = PWM_STATE_INACTIVE,
        .negative_brake_state = PWM_STATE_INACTIVE,
        .dead_time = 0,
    },
    {
        .positive_polarity = PWM_POLARITY_ACTIVE_LOW,
        .negative_polarity = PWM_POLARITY_ACTIVE_LOW,
        .positive_stop_state = PWM_STATE_ACTIVE,
        .negative_stop_state = PWM_STATE_ACTIVE,
        .positive_brake_state = PWM_STATE_ACTIVE,
        .negative_brake_state = PWM_STATE_INACTIVE,
        .dead_time = 0,
    }};

rt_inline void __read_pwm(uint8_t chan_id, float *dc) {
  *dc = __pwm_dc[chan_id];
}

rt_inline void __write_pwm(uint8_t chan_id, float dc) { //设置占空比

  struct bflb_device_s *pwm = bflb_device_get_by_name("pwm_v2_0");

  bflb_pwm_v2_channel_set_threshold(pwm, chan_id, 0, dc * cfg.period);

  __pwm_dc[chan_id] = dc;
}

static rt_err_t __set_pwm_frequency(uint16_t freq) {

  if (freq < 50 || freq > 500) {
    /* invalid frequency */
    return RT_EINVAL;
  }

  struct bflb_device_s *pwm = bflb_device_get_by_name("pwm_v2_0");
  bflb_pwm_v2_init(pwm, &cfg);
  // __pwm_freq = freq;

  for (uint8_t i = 0; i < PWM_V2_CH_MAX; i++) {
    __write_pwm(i, __pwm_dc[i]);
  }

  return RT_EOK;
}

static rt_err_t pwm_config(actuator_dev_t dev,
                           const struct actuator_configure *cfg) {

  if (__set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
    return RT_ERROR;
  }
  /* update device configuration */
  dev->config = *cfg;

  return RT_EOK;
}

static rt_err_t pwm_control(actuator_dev_t dev, int cmd, void *arg) {

  struct bflb_device_s *pwm = bflb_device_get_by_name("pwm_v2_0");

  rt_err_t ret = RT_EOK;

  switch (cmd) {
  case ACT_CMD_CHANNEL_ENABLE:
    /* set to lowest pwm before open */
    for (uint8_t i = 0; i < PWM_V2_CH_MAX; i++) {
          __write_pwm(i, 0.5);//相当于bflb_pwm_v2_channel_set_threshold(50)，50为cfg.period的一半，也就是电机刚好不转的状态
    }

    bflb_pwm_v2_start(pwm);
    break;
  case ACT_CMD_CHANNEL_DISABLE:
    bflb_pwm_v2_stop(pwm);
    break;
  case ACT_CMD_SET_PROTOCOL:
    /* TODO: Support dshot */
    ret = RT_EINVAL;
    break;
  default:
    ret = RT_EINVAL;
    break;
  }

  return ret;
}

static rt_size_t pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel,
                          rt_uint16_t *chan_val, rt_size_t size) {
  rt_uint16_t *index = chan_val;
  float dc;

  for (uint8_t i = 0; i < PWM_V2_CH_MAX; i++) {
    if (chan_sel & (1 << i)) {
      __read_pwm(i, &dc);
      *index = (1000000.0f / __pwm_freq * dc);
      index++;
    }
  }

  return size;
}

static rt_size_t pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel,
                           const rt_uint16_t *chan_val, rt_size_t size) {

  struct bflb_device_s *pwm = bflb_device_get_by_name("pwm_v2_0");
  const rt_uint16_t *index = chan_val;
  rt_uint16_t val;
  float dc;

  for (uint8_t i = 0; i < PWM_V2_CH_MAX; i++) {
    if (chan_sel & (1 << i)) {

      val = *index;
      dc = (float)(val * (80000000/(cfg.clk_div*cfg.period))) / 1000000.0f; // calculate pwm duty cycle
      if (dc > cfg.period) {
        LOG_E("Duty cycle exceeded the period.");
        return RT_ERROR;
      }

      __write_pwm(i, dc);
      index++;
    }
  }

  return size;
}

const static struct actuator_ops __act_ops = {.act_config = pwm_config,
                                              .act_control = pwm_control,
                                              .act_read = pwm_read,
                                              .act_write = pwm_write};

// TODO modify channel mask
static struct actuator_device act_dev = {
    .chan_mask = 0x3FF,
    .range = {1000, 2000},
    .config = {.protocol = ACT_PROTOCOL_PWM,
               .chan_num = PWM_V2_CH_MAX,
               .pwm_config = {.pwm_freq = 50},
               .dshot_config = {0}},
    .ops = &__act_ops};

int rt_hw_pwm_init(void)
{
    int result = RT_EOK;

    struct bflb_device_s* gpio = bflb_device_get_by_name("gpio");
    bflb_gpio_init(gpio, GPIO_PIN_1, // CH0N
                   GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLUP |
                       GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_3, // CH1N
                   GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLUP |
                       GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_29, // CH2N
                   GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLUP |
                       GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_30, // CH3P
                   GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLDOWN |
                       GPIO_SMT_EN | GPIO_DRV_1);
    struct bflb_device_s* pwm = bflb_device_get_by_name("pwm_v2_0");

    cfg.clk_source = BFLB_SYSTEM_PBCLK;
    cfg.clk_div = 1600;
    cfg.period = 100;
    bflb_pwm_v2_init(pwm, &cfg); // 500hz
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH0, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH1, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH2, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH3, 0, 50);
    bflb_pwm_v2_channel_init(pwm, PWM_CH0, &ch_cfg[0]);
    bflb_pwm_v2_channel_init(pwm, PWM_CH1, &ch_cfg[1]);
    bflb_pwm_v2_channel_init(pwm, PWM_CH2, &ch_cfg[2]);
    bflb_pwm_v2_channel_init(pwm, PWM_CH3, &ch_cfg[3]);
    bflb_pwm_v2_channel_positive_start(pwm, PWM_CH0);
    bflb_pwm_v2_channel_negative_start(pwm, PWM_CH0);
    bflb_pwm_v2_channel_positive_start(pwm, PWM_CH1);
    bflb_pwm_v2_channel_negative_start(pwm, PWM_CH1);
    bflb_pwm_v2_channel_positive_start(pwm, PWM_CH2);
    bflb_pwm_v2_channel_negative_start(pwm, PWM_CH2);
    bflb_pwm_v2_channel_positive_start(pwm, PWM_CH3);
    bflb_pwm_v2_channel_negative_start(pwm, PWM_CH3);

    result =
        hal_actuator_register(&act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL);
    if(result != RT_EOK)
    {
        LOG_E("pwm device register fail.");
    }
    return result;
}
// INIT_DEVICE_EXPORT(rt_hw_pwm_init);


static int pwmtest(int argc, char *argv[])
{
    struct bflb_device_s* pwm = bflb_device_get_by_name("pwm_v2_0");

    bflb_pwm_v2_start(pwm);
    rt_kprintf("pwm test start\n");
    bflb_mtimer_delay_ms(5000);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH0, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH1, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH2, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH3, 0, 50);
    bflb_mtimer_delay_ms(8000);
    rt_kprintf("pwm duty cycle 70\n");
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH0, 0, 70);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH1, 0, 70);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH2, 0, 70);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH3, 0, 70);
    bflb_mtimer_delay_ms(8000);
    rt_kprintf("pwm duty cycle 90\n");
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH0, 0, 90);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH1, 0, 90);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH2, 0, 90);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH3, 0, 90);
    bflb_mtimer_delay_ms(8000);
    rt_kprintf("pwm duty cycle 50, test end\n");
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH0, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH1, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH2, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH3, 0, 50);
}
MSH_CMD_EXPORT(pwmtest, pwm loopback test);

#endif /* BSP_USING_PWM */
