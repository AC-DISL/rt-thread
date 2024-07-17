/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date             Author          Notes
 * 2023-05-01       flyingcys       first version
 */

#include "bflb_dma.h"
#include "bflb_spi.h"
#include <rtdevice.h>
#include <rthw.h>
#include <rtthread.h>

#ifndef __DRV_SPI_H_
#define __DRV_SPI_H_

#ifdef SPI_SCK_USING_GPIO1
#define SPI_SCK_PIN GPIO_PIN_1
#elif defined(SPI_SCK_USING_GPIO5)
#define SPI_SCK_PIN GPIO_PIN_5
#elif defined(SPI_SCK_USING_GPIO9)
#define SPI_SCK_PIN GPIO_PIN_9
#elif defined(SPI_SCK_USING_GPIO13)
#define SPI_SCK_PIN GPIO_PIN_13
#elif defined(SPI_SCK_USING_GPIO17)
#define SPI_SCK_PIN GPIO_PIN_17
#elif defined(SPI_SCK_USING_GPIO21)
#define SPI_SCK_PIN GPIO_PIN_21
#elif defined(SPI_SCK_USING_GPIO25)
#define SPI_SCK_PIN GPIO_PIN_25
#elif defined(SPI_SCK_USING_GPIO29)
#define SPI_SCK_PIN GPIO_PIN_29
#elif defined(SPI_SCK_USING_GPIO33)
#define SPI_SCK_PIN GPIO_PIN_33
#endif

#ifdef SPI_MISO_USING_GPIO2
#define SPI_MISO_PIN GPIO_PIN_2
#elif defined(SPI_MISO_USING_GPIO6)
#define SPI_MISO_PIN GPIO_PIN_6
#elif defined(SPI_MISO_USING_GPIO10)
#define SPI_MISO_PIN GPIO_PIN_10
#elif defined(SPI_MISO_USING_GPIO14)
#define SPI_MISO_PIN GPIO_PIN_14
#elif defined(SPI_MISO_USING_GPIO18)
#define SPI_MISO_PIN GPIO_PIN_18
#elif defined(SPI_MISO_USING_GPIO22)
#define SPI_MISO_PIN GPIO_PIN_22
#elif defined(SPI_MISO_USING_GPIO26)
#define SPI_MISO_PIN GPIO_PIN_26
#elif defined(SPI_MISO_USING_GPIO30)
#define SPI_MISO_PIN GPIO_PIN_30
#elif defined(SPI_MISO_USING_GPIO34)
#define SPI_MISO_PIN GPIO_PIN_34
#endif

#ifdef SPI_MOSI_USING_GPIO3
#define SPI_MOSI_PIN GPIO_PIN_3
#elif defined(SPI_MOSI_USING_GPIO7)
#define SPI_MOSI_PIN GPIO_PIN_7
#elif defined(SPI_MOSI_USING_GPIO11)
#define SPI_MOSI_PIN GPIO_PIN_11
#elif defined(SPI_MOSI_USING_GPIO15)
#define SPI_MOSI_PIN GPIO_PIN_15
#elif defined(SPI_MOSI_USING_GPIO19)
#define SPI_MOSI_PIN GPIO_PIN_19
#elif defined(SPI_MOSI_USING_GPIO23)
#define SPI_MOSI_PIN GPIO_PIN_23
#elif defined(SPI_MOSI_USING_GPIO27)
#define SPI_MOSI_PIN GPIO_PIN_27
#elif defined(SPI_MOSI_USING_GPIO31)
#define SPI_MOSI_PIN GPIO_PIN_31
#endif

rt_err_t rt_hw_spi_device_attach(const char *bus_name, const char *device_name,
                                 rt_uint32_t cs_pin);
int rt_hw_spi_init(void);

#endif /*__DRV_SPI_H_*/