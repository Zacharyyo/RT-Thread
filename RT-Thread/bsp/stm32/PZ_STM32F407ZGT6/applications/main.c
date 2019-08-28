/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 */


#include <board.h>

int main(void)
{
    int count = 1;

    rt_kprintf("Hello World!\r\n");
    
    while (count++)
    {
        led1_blink();
    }

    return RT_EOK;
}
