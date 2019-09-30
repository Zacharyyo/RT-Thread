#include "board.h"

rt_adc_device_t adc_dev;
rt_uint32_t value , vol;
rt_err_t ret = RT_EOK;

void mq135_entry(void *parameter)
{
    for(;;)
    {
        /* 读取AD值 */
        value = rt_adc_read(adc_dev,ADC_DEV_CHANNEL);
        //rt_kprintf("MQ135 ADC Value is : %d\r\n",value);
        
        /* 电压转换 */
        vol = value * REF_VOLTAGE / CONVERT_BITS;
        //rt_kprintf("MQ135 Voltage is : %d.%02d\r\n\r\n",vol/100,vol%100);
        
        if(value <= 1200)
        {
            LCD_ShowString(124,188,tftlcd_data.width,tftlcd_data.height,16,"Excellent");
        }
        else if(value >1200 && value < 2400)
        {
            LCD_ShowString(124,188,tftlcd_data.width,tftlcd_data.height,16,"Good");
        }
        else
            LCD_ShowString(124,188,tftlcd_data.width,tftlcd_data.height,16,"Bad");
        
        rt_thread_delay(1000);
    }
}

/**
  * @brief  adc1_in5_init 初始化函数
  * @param  无
  * @retval 无
  */
static int adc1_in5_init(void)
{
    /* 获取设备号 */
    adc_dev = (rt_adc_device_t)rt_device_find(PM25_DEVICE_NAME);
    
    if(adc_dev == RT_NULL)
    {
        rt_kprintf("ADC Run Failed! Can not Find %s Device\r\n",PM25_DEVICE_NAME);
        return RT_ERROR;
    }
    
    /* 使能ADC设备 */
    ret = rt_adc_enable(adc_dev,ADC_DEV_CHANNEL);
    
    return ret;
}
INIT_COMPONENT_EXPORT(adc1_in5_init);


static int mq135_sample(void)
{
    rt_thread_t thread14;
    
    thread14 = rt_thread_create("mq135",
                                mq135_entry, RT_NULL,
                                1024,
                                14, 20);
    
    if(thread14 != RT_NULL)
    {
        rt_thread_startup(thread14);
    }
    
    return RT_EOK;
}
INIT_APP_EXPORT(mq135_sample);

