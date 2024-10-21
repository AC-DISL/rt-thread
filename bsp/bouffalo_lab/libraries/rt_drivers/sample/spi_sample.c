/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-05-01     flyingcys    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "bflb_gpio.h"

#ifdef BSP_USING_SPI

#define BUS_NAME     "spi0"
#define SPI_NAME     "spi0_dev0"

static struct rt_spi_device *spi_dev = RT_NULL;


/* attach spi5 device */
static int spi_device_init(void)
{
    struct rt_spi_configuration cfg;

    // rt_hw_spi_device_attach(BUS_NAME, SPI_NAME, RT_NULL);

    cfg.data_width = 8;
    cfg.mode   = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB | RT_SPI_NO_CS;
    cfg.max_hz = 10 *1000 *1000;

    spi_dev = (struct rt_spi_device *)rt_device_find(SPI_NAME);

    struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

    if (RT_NULL == spi_dev)
    {
        rt_kprintf("spi sample run failed! can't find %s device!\n", SPI_NAME);
        return -RT_ERROR;
    }

    rt_spi_configure(spi_dev, &cfg);

    return RT_EOK;
}
// INIT_APP_EXPORT(spi_device_init);

/* spi loopback mode test case */
static int spi_sample(int argc, char **argv)
{
    struct rt_spi_configuration cfg;

    // rt_hw_spi_device_attach(BUS_NAME, SPI_NAME, RT_NULL);

    cfg.data_width = 8;
    cfg.mode   = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB | RT_SPI_NO_CS;
    cfg.max_hz = 10 *1000 *1000;

    spi_dev = (struct rt_spi_device *)rt_device_find(SPI_NAME);

    struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

    if (RT_NULL == spi_dev)
    {
        rt_kprintf("spi sample run failed! can't find %s device!\n", SPI_NAME);
        return -RT_ERROR;
    }

    rt_spi_configure(spi_dev, &cfg);
    
    
    rt_uint8_t t_buf[8], r_buf[8];
    int i = 0;
    static struct rt_spi_message msg1;

    if (argc != 9)
    {
        rt_kprintf("Please Usage:\n");
        rt_kprintf("spi_sample 1 2 3 4 5 6 7 8\n");
        return -RT_ERROR;
    }

    for (i = 0; i < 8; i++)
    {
        t_buf[i] = atoi(argv[i+1]);
    }

    msg1.send_buf   = &t_buf;
    msg1.recv_buf   = &r_buf;
    msg1.length     = sizeof(t_buf);
    msg1.cs_take    = 1;
    msg1.cs_release = 0;
    msg1.next       = RT_NULL;

    rt_spi_transfer_message(spi_dev, &msg1);

    rt_kprintf("spi rbuf : ");
    for (i = 0; i < sizeof(t_buf); i++)
    {
        rt_kprintf("%x ", r_buf[i]);
    }

    rt_kprintf("\nspi loopback mode test over!\n");

    return RT_EOK;
}
MSH_CMD_EXPORT(spi_sample, spi loopback test);

static int setio(int argc, char **argv)
{
    
    struct bflb_device_s *gpio;
    gpio = bflb_device_get_by_name("gpio");
    printf("gpio output\r\n");
    bflb_gpio_init(gpio, GPIO_PIN_13, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(gpio, GPIO_PIN_14, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(gpio, GPIO_PIN_15, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(gpio, GPIO_PIN_11, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);

    while (1) {
        bflb_gpio_set(gpio, GPIO_PIN_13);
        bflb_gpio_set(gpio, GPIO_PIN_14);
        bflb_gpio_set(gpio, GPIO_PIN_15);
        printf("GPIO_PIN_12=%x\r\n", bflb_gpio_read(gpio, GPIO_PIN_14));
        bflb_mtimer_delay_ms(2000);

        bflb_gpio_reset(gpio, GPIO_PIN_13);
        bflb_gpio_reset(gpio, GPIO_PIN_14);
        bflb_gpio_reset(gpio, GPIO_PIN_15);
        printf("GPIO_PIN_12=%x\r\n", bflb_gpio_read(gpio, GPIO_PIN_14));
        bflb_mtimer_delay_ms(2000);
    }
}
MSH_CMD_EXPORT(setio, spi loopback test);
#endif /* BSP_USING_SPI */
