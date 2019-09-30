#ifndef __DRV_PM25_H_
#define __DRV_PM25_H_

#include <drv_common.h>

#define PM25_DEVICE_NAME     "adc1"      /* ADC 设备名称 */
#define PM25_DEV_CHANNEL     7           /* ADC 通道 */
#define REF_VOLTAGE         330         /* 参考电压 3.3V,数据精度乘以100保留2位小数*/
#define CONVERT_BITS        (1 << 12)   /* 转换位数为12位 */


#endif	/* __DRV_PM25_H_ */

