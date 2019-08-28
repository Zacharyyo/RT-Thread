#include "board.h"

rt_adc_device_t adc_dev;
rt_uint32_t value , vol;
rt_err_t ret = RT_EOK;

void get_adc1_in5_vlaue(void)
{
    /* 读取AD值 */
    value = rt_adc_read(adc_dev,ADC_DEV_CHANNEL);
    rt_kprintf("The ADC Value is : %d\r\n",value);
    
    /* 电压转换 */
    vol = value * REF_VOLTAGE / CONVERT_BITS;
    rt_kprintf("The Voltage is : %d.%02d\r\n",vol/100,vol%100);
}
MSH_CMD_EXPORT(get_adc1_in5_vlaue,get_adc1_vlaue);
/**
  * @brief  adc1_in5_init 初始化函数
  * @param  无
  * @retval 无
  */
static int adc1_in5_init(void)
{
    /* 获取设备号 */
    adc_dev = (rt_adc_device_t)rt_device_find(ADC_DEVICE_NAME);
    
    if(adc_dev == RT_NULL)
    {
        rt_kprintf("ADC Run Failed! Can not Find %s Device\r\n",ADC_DEVICE_NAME);
        return RT_ERROR;
    }
    
    /* 使能ADC设备 */
    ret = rt_adc_enable(adc_dev,ADC_DEV_CHANNEL);
    
    return ret;
}
INIT_APP_EXPORT(adc1_in5_init);
MSH_CMD_EXPORT(adc1_in5_init,adc1_in5_init);




