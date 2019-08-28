#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>


/**
  * @brief  key_up_cb 上按键回调函数
  * @param  void *args
  * @retval 无
  */
static void key_up_cb(void *args)
{
    /* 如果读取到高电平，点亮led2 */
    if(rt_pin_read(KEY_UP))
    {
        /* do something */
        led2_on();         
    }
}

/**
  * @brief  key_down_cb 下按键回调函数
  * @param  void *args
  * @retval 无
  */
static void key_down_cb(void *args)
{
    if(rt_pin_read(KEY_DOWN) == 0)
    {
        /* do something */
        led2_off();
    }
}

/**
  * @brief  key_left_cb 左按键回调函数
  * @param  void *args
  * @retval 无
  */
static void key_left_cb(void *args)
{
    if(rt_pin_read(KEY_LEFT) == 0)
    {
        /* do something */
        
    }
}

/**
  * @brief  key_right_cb 右按键回调函数
  * @param  void *args
  * @retval 无
  */
static void key_right_cb(void *args)
{
    if(rt_pin_read(KEY_RIGHT) == 0)
    {
        /* do something */
        
    }
}

/**
  * @brief  key_init 按键初始化 
  * @param  无
  * @retval 无
  */
int key_init(void)
{
    /* 按键模式设置 */
    rt_pin_mode(KEY_UP,PIN_MODE_INPUT_PULLDOWN);//KEY_UP
    rt_pin_mode(KEY_DOWN,PIN_MODE_INPUT_PULLUP);//KEY_DOWN
    rt_pin_mode(KEY_LEFT,PIN_MODE_INPUT_PULLUP);//KEY_LEFT
    rt_pin_mode(KEY_RIGHT,PIN_MODE_INPUT_PULLUP);//KEY_RIGHT
    
    /* 绑定引脚中断回调函数 */
    rt_pin_attach_irq(KEY_UP, PIN_IRQ_MODE_RISING, key_up_cb,RT_NULL);
    rt_pin_attach_irq(KEY_DOWN, PIN_IRQ_MODE_FALLING, key_down_cb,RT_NULL);
    rt_pin_attach_irq(KEY_LEFT, PIN_IRQ_MODE_FALLING, key_left_cb,RT_NULL);
    rt_pin_attach_irq(KEY_RIGHT, PIN_IRQ_MODE_FALLING, key_right_cb,RT_NULL);
    
    /* 使能引脚中断 */
    rt_pin_irq_enable(KEY_UP,ENABLE);
    rt_pin_irq_enable(KEY_DOWN,ENABLE);
    rt_pin_irq_enable(KEY_LEFT,ENABLE);
    rt_pin_irq_enable(KEY_RIGHT,ENABLE);
    
    /* 脱离绑定引脚中断回调函数 */
    //rt_pin_detach_irq(KEY_UP);//解除绑定后可重新使用rt_pin_attach_irq()函数绑定相关或其他中断函数
    
    return RT_EOK;
}
INIT_APP_EXPORT( key_init );
MSH_CMD_EXPORT(key_init,key init);
