
#include <board.h>

#define SENSOR_DEBUG
#define DBG_TAG               "sensor.pm2.5"

#ifdef SENSOR_DEBUG
#define DBG_LVL               DBG_LOG
#else
#define DBG_LVL               DBG_ERROR
#endif /* SENSOR_DEBUG */


/* Modify this pin according to the actual wiring situation */
#define PM25_DATA_PIN    GET_PIN(A,7)


rt_adc_device_t pm25_adc_dev;
rt_uint32_t pm25_value , pm25_vol;
rt_err_t pm25_ret = RT_EOK;

static void read_pm25_entry(void *parameter)
{
    for(;;)
    {
        /* 读取AD值 */
        pm25_value = rt_adc_read(pm25_adc_dev,PM25_DEV_CHANNEL);
        rt_kprintf("PM2.5 ADC Value is : %d\r\n",pm25_value);
        
        /* 电压转换 */
        pm25_vol = pm25_value * REF_VOLTAGE / CONVERT_BITS;
        rt_kprintf("PM2.5 Voltage is : %d.%02d\r\n\r\n",pm25_vol / 100,pm25_vol % 100);
        
        rt_thread_delay(1000);
    }
}

/**
  * @brief  adc1_in5_init 初始化函数
  * @param  无
  * @retval 无
  */
static int adc1_in7_init(void)
{
    /* 获取设备号 */
    pm25_adc_dev = (rt_adc_device_t)rt_device_find(PM25_DEVICE_NAME);
    
    if(pm25_adc_dev == RT_NULL)
    {
        rt_kprintf("ADC Run Failed! Can not Find %s Device\r\n",PM25_DEVICE_NAME);
        return RT_ERROR;
    }
    
    /* 使能ADC设备 */
    pm25_ret = rt_adc_enable(pm25_adc_dev,PM25_DEV_CHANNEL);
    
    return pm25_ret;
}
INIT_COMPONENT_EXPORT(adc1_in7_init);


static int pm25_sample(void)
{
    static rt_thread_t thread15 = RT_NULL;
    
    thread15 = rt_thread_create("pm2.5",
                                read_pm25_entry,
                                RT_NULL,
                                1024,
                                15,
                                20);
    if(thread15 != RT_NULL)
    {
        rt_thread_startup(thread15);
    }
    
    return RT_EOK;
}
INIT_APP_EXPORT(pm25_sample);








