#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>


void led1_on(void)
{
    rt_pin_write(LED1_PIN,PIN_LOW);
}
void led1_off(void)
{
    rt_pin_write(LED1_PIN,PIN_HIGH);
}
void led1_blink(void)
{
    rt_pin_write(LED1_PIN,PIN_LOW);
    rt_thread_mdelay(100);
    rt_pin_write(LED1_PIN,PIN_HIGH);
    rt_thread_mdelay(100);
}

void led2_on(void)
{
    rt_pin_write(LED2_PIN,PIN_LOW);
}
void led2_off(void)
{
    rt_pin_write(LED2_PIN,PIN_HIGH);
}
void led2_blink(void)
{
    rt_pin_write(LED2_PIN,PIN_LOW);
    rt_thread_mdelay(250);
    rt_pin_write(LED2_PIN,PIN_HIGH);
    rt_thread_mdelay(250);
}

static int led_init(void)
{
    /* 设置LED引脚为输出模式 */
    rt_pin_mode(LED1_PIN,PIN_MODE_OUTPUT);
    rt_pin_mode(LED2_PIN, PIN_MODE_OUTPUT);    
    
    /* 关闭LED */
    rt_pin_write(LED1_PIN,PIN_HIGH);
    rt_pin_write(LED2_PIN,PIN_HIGH);
    
    return RT_EOK;
}
INIT_APP_EXPORT( led_init );
//MSH_CMD_EXPORT(led_init, led init);
