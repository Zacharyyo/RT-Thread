#ifndef __LED_ALERT_H_
#define __LED_ALERT_H_

//#include <drv_common.h>

//LED1_PIN-->PF9
//LED2_PIN-->PF10
//µÕµÁ∆Ω¡¡
/* defined the LED1 pin: PF9 */
#define LED1_PIN    GET_PIN(F, 9)
/* defined the LED2 pin: PF10 */
#define LED2_PIN    GET_PIN(F, 10)

void led1_on(void);
void led1_off(void);
void led1_blink(void);

void led2_on(void);
void led2_off(void);
void led2_blink(void);

#endif 

