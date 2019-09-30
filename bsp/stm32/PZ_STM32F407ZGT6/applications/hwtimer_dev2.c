#include "board.h"


#define HWTIMER_DEV_NAME   "timer2"      /* 定时器名称 */


static rt_err_t hw_timer2out_cb(rt_device_t dev, rt_size_t size)
{
    rt_kprintf("This is hw_timer2 call back\r\n");
    return 0 ;
}


static int hw_timer2_init(void)
{
    rt_err_t ret = RT_EOK;
    rt_device_t hw_dev2;                     /* 定时器设备句柄 */
    rt_hwtimer_mode_t mode2;                 /* 定时器模式 */
//    rt_uint32_t freq2 = 10000;               /* 计数频率 */
    rt_hwtimerval_t timeout_val;


    
    hw_dev2 = rt_device_find(HWTIMER_DEV_NAME);     //查找设备，该函数在device.c中
    
    if(hw_dev2 == NULL )
    {
        rt_kprintf("Can Not Find Device : %d\r\n",HWTIMER_DEV_NAME);
    }   
    
    ret = rt_device_open(hw_dev2,RT_DEVICE_OFLAG_RDWR);   //以读写打开设备

    if(ret != RT_EOK )
    {
        rt_kprintf("Open Device : %s Failed\r\n",HWTIMER_DEV_NAME);
        return ret;
    }   

    rt_device_set_rx_indicate(hw_dev2,hw_timer2out_cb);                    //设置定时器中断回调函数
    
    mode2 = HWTIMER_MODE_PERIOD;                //自动重装载
    
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
MSH_CMD_EXPORT(hw_timer2_init, hwtimer2 init);  //添加到msh命令
//INIT_APP_EXPORT( hw_timer2_init );//自动初始化
