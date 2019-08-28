#ifndef __BSP_ADC_H_
#define __BSP_ADC_H_


#define ADC_DEVICE_NAME     "adc1"      /* ADC 设备名称 */
#define ADC_DEV_CHANNEL     5           /* ADC 通道 */
#define REF_VOLTAGE         330         /* 参考电压 3.3V,数据精度乘以100保留2位小数*/
#define CONVERT_BITS        (1 << 12)   /* 转换位数为12位 */

void get_adc1_in5_vlaue(void);


#endif /* __BSP_ADC_H_ */









