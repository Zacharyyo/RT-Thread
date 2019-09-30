#include "board.h"


#define HWTIMER_DEV_NAME   "timer2"      /* ��ʱ������ */


static rt_err_t hw_timer2out_cb(rt_device_t dev, rt_size_t size)
{
    rt_kprintf("This is hw_timer2 call back\r\n");
    return 0 ;
}


static int hw_timer2_init(void)
{
    rt_err_t ret = RT_EOK;
    rt_device_t hw_dev2;                     /* ��ʱ���豸��� */
    rt_hwtimer_mode_t mode2;                 /* ��ʱ��ģʽ */
//    rt_uint32_t freq2 = 10000;               /* ����Ƶ�� */
    rt_hwtimerval_t timeout_val;


    
    hw_dev2 = rt_device_find(HWTIMER_DEV_NAME);     //�����豸���ú�����device.c��
    
    if(hw_dev2 == NULL )
    {
        rt_kprintf("Can Not Find Device : %d\r\n",HWTIMER_DEV_NAME);
    }   
    
    ret = rt_device_open(hw_dev2,RT_DEVICE_OFLAG_RDWR);   //�Զ�д���豸

    if(ret != RT_EOK )
    {
        rt_kprintf("Open Device : %s Failed\r\n",HWTIMER_DEV_NAME);
        return ret;
    }   

    rt_device_set_rx_indicate(hw_dev2,hw_timer2out_cb);                    //���ö�ʱ���жϻص�����
    
    mode2 = HWTIMER_MODE_PERIOD;                //�Զ���װ��
    
    ret = rt_device_control(hw_dev2,HWTIMER_CTRL_MODE_SET,&mode2);
    
    if(ret != RT_EOK )
    {
        rt_kprintf("Set Mode Failed,The ret is %d\r\n",ret);
        return ret;
    }   
    
    timeout_val.sec = 2;
    timeout_val.usec = 0;
    if( rt_device_write(hw_dev2,0,&timeout_val,sizeof(timeout_val)) != sizeof(timeout_val) )
    {
        rt_kprintf("Set Timeout Value Failed\r\n");
        return RT_ERROR;
    }
    
    return ret;
}
MSH_CMD_EXPORT(hw_timer2_init, hwtimer2 init);  //��ӵ�msh����
//INIT_APP_EXPORT( hw_timer2_init );//�Զ���ʼ��
