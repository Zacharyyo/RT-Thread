/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-08-27     Zachary      First Version
 */


#include <board.h>


int main(void)
{
    int count = 1;

    rt_kprintf("Hello World!\r\n");
    
    rt_thread_mdelay(50);
    
	FRONT_COLOR = RED;
    
    LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,12," \\ | / ");
    LCD_ShowString(10,28,tftlcd_data.width,tftlcd_data.height,12,"-  RT -    Thread Operating System");
    LCD_ShowString(10,46,tftlcd_data.width,tftlcd_data.height,12," / | \\    4.0.1 ");
    LCD_ShowString(6,64,tftlcd_data.width,tftlcd_data.height,12,"2006 - 2019 Copyright by rt-thread team");
    
	LCD_ShowString(10,80,tftlcd_data.width,tftlcd_data.height,12,"STM32 --- RT-Thread V4.0.1");
	LCD_ShowString(10,110,tftlcd_data.width,tftlcd_data.height,24,"Temperature :    C");
	LCD_ShowString(10,140,tftlcd_data.width,tftlcd_data.height,24,"Huminity :    RH%");
    
    LCD_ShowString(10,188,tftlcd_data.width,tftlcd_data.height,16,"Air Quality :     ");
    
    
    while (count++)
    {
        led1_blink();
        
    }

    return RT_EOK;
}
