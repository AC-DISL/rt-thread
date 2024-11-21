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
#include "hal/rc/ppm.h"
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

static ppm_decoder_t ppm_decoder;
struct bflb_device_s *timer0;
struct bflb_device_s *gpio;

void gpio_isr(int irq, void *arg) {

  rt_interrupt_enter();
  uint32_t ic_val = bflb_timer_get_countervalue(timer0);

  static int i = 0;
  bool intstatus = bflb_gpio_get_intstatus(gpio, GPIO_PIN_10);
  if (intstatus) {
    bflb_gpio_int_clear(gpio, GPIO_PIN_10);
    ppm_update(&ppm_decoder, ic_val); // PPM信号捕获
  }

  rt_interrupt_leave();
}

//定时器用于记录中断触发的时间戳，配置输入捕获通道用于触发中断
static rt_err_t ppm_lowlevel_init(void) {

  gpio = bflb_device_get_by_name("gpio");

  bflb_gpio_int_init(gpio, GPIO_PIN_10,
                     GPIO_INT_TRIG_MODE_SYNC_RISING_EDGE); //上升沿触发
  bflb_gpio_int_mask(gpio, GPIO_PIN_10, false);

  bflb_irq_attach(gpio->irq_num, gpio_isr, gpio);
  bflb_irq_enable(gpio->irq_num);

  // timer configurations
  struct bflb_timer_config_s cfg0;
  cfg0.counter_mode = TIMER_COUNTER_MODE_UP; /* preload when match occur */
  cfg0.clock_source = TIMER_CLKSRC_XTAL;          // 40M
  cfg0.clock_div = 39; /* for bl616/bl808/bl606p is 39, for bl702 is 31 */
  cfg0.trigger_comp_id = TIMER_COMP_ID_0;
  cfg0.comp0_val = 65535;   /* match value 0  */
  cfg0.comp1_val = 1500000; /* match value 1 */
  cfg0.comp2_val = 2500000; /* match value 2 */
  cfg0.preload_val = 0;     /* preload value */

  timer0 = bflb_device_get_by_name("timer0");
  bflb_timer_init(timer0, &cfg0);

  bflb_timer_start(timer0);

  return RT_EOK;
}

static rt_err_t rc_control(rc_dev_t rc, int cmd, void *arg) {
  switch (cmd) {
  case RC_CMD_CHECK_UPDATE: {
    uint8_t updated = 0;

    updated = ppm_data_ready(&ppm_decoder);

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

  if (ppm_data_ready(&ppm_decoder) == 0) {
    /* no data received, just return */
    return 0;
  }

  ppm_lock(&ppm_decoder);

  for (uint8_t i = 0; i < min(rc->config.channel_num, ppm_decoder.total_chan);
       i++) {
    if (chan_mask & (1 << i)) {
      *(index++) = ppm_decoder.ppm_val[i];
      rb += 2;
    }
  }
  ppm_data_clear(&ppm_decoder);

  ppm_unlock(&ppm_decoder);

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

  RT_CHECK(hal_rc_register(&rc_dev, "rc", RT_DEVICE_FLAG_RDWR, NULL));

  return RT_EOK;
}