#ifndef __BSP_ADC_H_
#define __BSP_ADC_H_


#define ADC_DEVICE_NAME     "adc1"      /* ADC �豸���� */
#define ADC_DEV_CHANNEL     5           /* ADC ͨ�� */
#define REF_VOLTAGE         330         /* �ο���ѹ 3.3V,���ݾ��ȳ���100����2λС��*/
#define CONVERT_BITS        (1 << 12)   /* ת��λ��Ϊ12λ */

void get_adc1_in5_vlaue(void);


#endif /* __BSP_ADC_H_ */









