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

#define DBG_LEVEL DBG_LOG
#include <rtdbg.h>
#define LOG_TAG "DRV.PWM"
#include "hal/actuator/actuator.h"

#ifdef BSP_USING_PWM

static uint32_t __pwm_freq;
static float __pwm_dc[PWM_V2_CH_MAX];

static struct bflb_pwm_v2_config_s cfg;

struct bflb_pwm_v2_channel_config_s ch_cfg[PWM_V2_CH_MAX] = {
    {
        .positive_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .negative_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .positive_stop_state = PWM_STATE_INACTIVE,
        .negative_stop_state = PWM_STATE_ACTIVE,
        .positive_brake_state = PWM_STATE_INACTIVE,
        .negative_brake_state = PWM_STATE_ACTIVE,
        .dead_time = 0,
    },
    {
        .positive_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .negative_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .positive_stop_state = PWM_STATE_ACTIVE,
        .negative_stop_state = PWM_STATE_INACTIVE,
        .positive_brake_state = PWM_STATE_ACTIVE,
        .negative_brake_state = PWM_STATE_ACTIVE,
        .dead_time = 0,
    },
    {
        .positive_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .negative_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .positive_stop_state = PWM_STATE_INACTIVE,
        .negative_stop_state = PWM_STATE_INACTIVE,
        .positive_brake_state = PWM_STATE_INACTIVE,
        .negative_brake_state = PWM_STATE_INACTIVE,
        .dead_time = 0,
    },
    {
        .positive_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .negative_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .positive_stop_state = PWM_STATE_ACTIVE,
        .negative_stop_state = PWM_STATE_ACTIVE,
        .positive_brake_state = PWM_STATE_ACTIVE,
        .negative_brake_state = PWM_STATE_INACTIVE,
        .dead_time = 0,
    }};

static rt_err_t _pwm_set(rt_uint8_t channel, struct rt_pwm_configuration *configuration)
{
    struct bflb_device_s* pwm = bflb_device_get_by_name("pwm_v2_0");

    uint32_t period_hz = 1000000000 / configuration->period;

    struct bflb_pwm_v2_config_s pwm_config;

    pwm_config.clk_source = BFLB_SYSTEM_XCLK;

    pwm_config.clk_div = 40;

    pwm_config.period = 1000000 / period_hz;

    bflb_pwm_v2_init(pwm, &pwm_config);

    struct bflb_pwm_v2_channel_config_s pwm_ch_config = {
        .positive_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .negative_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .positive_stop_state = PWM_STATE_INACTIVE,
        .negative_stop_state = PWM_STATE_ACTIVE,
        .positive_brake_state = PWM_STATE_INACTIVE,
        .negative_brake_state = PWM_STATE_INACTIVE,
        .dead_time = 0,
    };

    bflb_pwm_v2_channel_init(pwm, channel, &pwm_ch_config);

    bflb_pwm_v2_channel_set_threshold(pwm, channel, 0, configuration->pulse);

    bflb_pwm_v2_channel_positive_stop(pwm, channel);
    bflb_pwm_v2_channel_negative_stop(pwm, channel);
    bflb_pwm_v2_stop(pwm);

    bflb_pwm_v2_channel_positive_start(pwm, channel);
    bflb_pwm_v2_channel_negative_start(pwm, channel);
    bflb_pwm_v2_start(pwm);

    return RT_EOK;
}

static rt_err_t _pwm_get(rt_uint8_t channel, struct rt_pwm_configuration *configuration)
{
    uint32_t reg_base, regval, tmp;
    float period;

    reg_base = bflb_device_get_by_name("pwm_v2_0")->reg_base;
    regval = getreg32(reg_base + PWM_MC0_PERIOD_OFFSET);
    tmp = (regval & PWM_PERIOD_MASK) >> PWM_PERIOD_SHIFT;
    period = (float)tmp;

    uint32_t period_hz = 1000000 / period;

    regval = getreg32(reg_base + PWM_MC0_CH0_THRE_OFFSET + channel * 4);
    uint16_t high_threhold = regval >> 16;
    uint16_t low_threhold = regval;

    configuration->period = 1000000000 / period_hz;

    configuration->pulse = high_threhold;

    return RT_EOK;
}

static rt_err_t _pwm_control(struct rt_device_pwm *device, int cmd, void *arg)
{
    struct rt_pwm_configuration *configuration = (struct rt_pwm_configuration *)arg;

    rt_uint32_t channel = 0;

    channel = configuration->channel;

    if (channel >= 4)
        return -RT_EINVAL;

    struct bflb_device_s* pwm = bflb_device_get_by_name("pwm_v2_0");
    switch (cmd)
    {
    case ACT_CMD_CHANNEL_ENABLE:
      bflb_pwm_v2_channel_positive_start(pwm, channel);
      bflb_pwm_v2_channel_negative_start(pwm, channel);
      return RT_EOK;
    case ACT_CMD_CHANNEL_DISABLE:
      bflb_pwm_v2_channel_positive_stop(pwm, channel);
      bflb_pwm_v2_channel_negative_stop(pwm, channel);
      return RT_EOK;
    case ACT_CMD_SET_PROTOCOL:
      return _pwm_set(channel, configuration);
    default:
        return -RT_EINVAL;
    }
}

rt_inline void __read_pwm(uint8_t chan_id, float *dc) {
  *dc = __pwm_dc[chan_id];
}

rt_inline void __write_pwm(uint8_t chan_id, float dc) { //设置占空比

  struct bflb_device_s *pwm = bflb_device_get_by_name("pwm_v2_0");

  bflb_pwm_v2_channel_set_threshold(pwm, chan_id, 0, dc * cfg.period);

  __pwm_dc[chan_id] = dc;
}

static rt_err_t __set_pwm_frequency(uint16_t freq) {

  if (freq < 50 || freq > 400) {
    /* invalid frequency */
    return RT_EINVAL;
  }

  struct bflb_device_s *pwm = bflb_device_get_by_name("pwm_v2_0");
  cfg.clk_div = cfg.clk_source / (cfg.period * freq);

  bflb_pwm_v2_init(pwm, &cfg);
  __pwm_freq = freq;

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

  struct rt_pwm_configuration *configuration =
      (struct rt_pwm_configuration *)arg;

  rt_uint32_t channel = 0;

  channel = configuration->channel;

  if (channel >= 4)
    return -RT_EINVAL;

  struct bflb_device_s *pwm = bflb_device_get_by_name("pwm_v2_0");

  rt_err_t ret = RT_EOK;

  switch (cmd) {
  case ACT_CMD_CHANNEL_ENABLE:
    /* set to lowest pwm before open */
    bflb_pwm_v2_channel_positive_start(pwm, channel);
    bflb_pwm_v2_channel_negative_start(pwm, channel);
    break;
  case ACT_CMD_CHANNEL_DISABLE:
    bflb_pwm_v2_channel_positive_stop(pwm, channel);
    bflb_pwm_v2_channel_negative_stop(pwm, channel);
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
      dc = (float)(val * __pwm_freq) / 1000000.0f; // calculate pwm duty cycle
      LOG_E("PWM set dc:%f", dc);
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

// static struct rt_pwm_ops _pwm_ops =
// {
//     _pwm_control
// };
// static struct rt_device_pwm pwm_device;

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
    cfg.clk_div = 16000;
    cfg.period = 100;
    __pwm_freq = cfg.clk_source / (cfg.clk_div * cfg.period);
    bflb_pwm_v2_init(pwm, &cfg); // 50hz
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH0, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH1, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH2, 0, 50);
    bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH3, 0, 50);
    bflb_pwm_v2_channel_negative_start(pwm, PWM_CH0);
    bflb_pwm_v2_channel_negative_start(pwm, PWM_CH1);
    bflb_pwm_v2_channel_negative_start(pwm, PWM_CH2);
    bflb_pwm_v2_channel_positive_start(pwm, PWM_CH3);
    bflb_pwm_v2_start(pwm);

    // result = rt_device_pwm_register(&pwm_device, "pwm", &_pwm_ops, 0);
    result =
        hal_actuator_register(&act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL);
    if(result != RT_EOK)
    {
        LOG_E("pwm device register fail.");
    }
    return result;
}
// INIT_DEVICE_EXPORT(rt_hw_pwm_init);

#endif /* BSP_USING_PWM */
