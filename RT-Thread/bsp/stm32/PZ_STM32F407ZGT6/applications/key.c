#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>


/**
  * @brief  key_up_cb �ϰ����ص�����
  * @param  void *args
  * @retval ��
  */
static void key_up_cb(void *args)
{
    /* �����ȡ���ߵ�ƽ������led2 */
    if(rt_pin_read(KEY_UP))
    {
        /* do something */
        led2_on();         
    }
}

/**
  * @brief  key_down_cb �°����ص�����
  * @param  void *args
  * @retval ��
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
  * @brief  key_left_cb �󰴼��ص�����
  * @param  void *args
  * @retval ��
  */
static void key_left_cb(void *args)
{
    if(rt_pin_read(KEY_LEFT) == 0)
    {
        /* do something */
        
    }
}

/**
  * @brief  key_right_cb �Ұ����ص�����
  * @param  void *args
  * @retval ��
  */
static void key_right_cb(void *args)
{
    if(rt_pin_read(KEY_RIGHT) == 0)
    {
        /* do something */
        
    }
}

/**
  * @brief  key_init ������ʼ�� 
  * @param  ��
  * @retval ��
  */
int key_init(void)
{
    /* ����ģʽ���� */
    rt_pin_mode(KEY_UP,PIN_MODE_INPUT_PULLDOWN);//KEY_UP
    rt_pin_mode(KEY_DOWN,PIN_MODE_INPUT_PULLUP);//KEY_DOWN
    rt_pin_mode(KEY_LEFT,PIN_MODE_INPUT_PULLUP);//KEY_LEFT
    rt_pin_mode(KEY_RIGHT,PIN_MODE_INPUT_PULLUP);//KEY_RIGHT
    
    /* �������жϻص����� */
    rt_pin_attach_irq(KEY_UP, PIN_IRQ_MODE_RISING, key_up_cb,RT_NULL);
    rt_pin_attach_irq(KEY_DOWN, PIN_IRQ_MODE_FALLING, key_down_cb,RT_NULL);
    rt_pin_attach_irq(KEY_LEFT, PIN_IRQ_MODE_FALLING, key_left_cb,RT_NULL);
    rt_pin_attach_irq(KEY_RIGHT, PIN_IRQ_MODE_FALLING, key_right_cb,RT_NULL);
    
    /* ʹ�������ж� */
    rt_pin_irq_enable(KEY_UP,ENABLE);
    rt_pin_irq_enable(KEY_DOWN,ENABLE);
    rt_pin_irq_enable(KEY_LEFT,ENABLE);
    rt_pin_irq_enable(KEY_RIGHT,ENABLE);
    
    /* ����������жϻص����� */
    //rt_pin_detach_irq(KEY_UP);//����󶨺������ʹ��rt_pin_attach_irq()��������ػ������жϺ���
    
    return RT_EOK;
}
INIT_APP_EXPORT( key_init );
MSH_CMD_EXPORT(key_init,key init);
