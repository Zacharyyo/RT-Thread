#ifndef _tftlcd_H
#define _tftlcd_H

#include <rtthread.h>
#include <rtdevice.h>
#include "stm32f4xx.h"

//定义LCD彩屏的驱动类型  可根据自己手上的彩屏背面型号来选择打开哪种驱动
//#define TFTLCD_HX8357D 

#define TFTLCD_HX8352C

//#define TFTLCD_ILI9488

//#define TFTLCD_ST7793

//#define TFTLCD_NT5510


//TFTLCD地址结构体
typedef struct
{
	rt_uint16_t LCD_CMD;
	rt_uint16_t LCD_DATA;
}TFTLCD_TypeDef;


//使用NOR/SRAM的 Bank1.sector4,地址位HADDR[27,26]=11 A6作为数据命令区分线 
//注意设置时STM32内部会右移一位对齐! 111 1110=0X7E			    
#define TFTLCD_BASE        ((int)(0x6C000000 | 0x0000007E))
#define TFTLCD             ((TFTLCD_TypeDef *) TFTLCD_BASE)



//TFTLCD重要参数集
typedef struct  
{										    
	rt_uint16_t width;			//LCD 宽度
	rt_uint16_t height;			//LCD 高度
	rt_uint16_t id;				//LCD ID
	rt_uint8_t  dir;            //LCD 方向
}_tftlcd_data;


//LCD参数
extern _tftlcd_data tftlcd_data;	//管理LCD重要参数
//LCD的前端颜色和背景色	   
extern rt_uint16_t  FRONT_COLOR;//前端颜色 默认红色    
extern rt_uint16_t  BACK_COLOR; //背景颜色.默认为白色


//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色


int TFTLCD_Init(void);

void LCD_WriteCmd(rt_uint16_t cmd);
void LCD_WriteData(rt_uint16_t data);
void LCD_WriteCmdData(rt_uint16_t cmd,rt_uint16_t data);
void LCD_WriteData_Color(rt_uint16_t color);

void LCD_Set_Window(rt_uint16_t sx,rt_uint16_t sy,rt_uint16_t width,rt_uint16_t height);
void LCD_Clear(rt_uint16_t Color);	 												//清屏
void LCD_Fill(rt_uint16_t xState,rt_uint16_t yState,rt_uint16_t xEnd,rt_uint16_t yEnd,rt_uint16_t color);
void LCD_DrawPoint(rt_uint16_t x,rt_uint16_t y);//画点
void LCD_DrawFRONT_COLOR(rt_uint16_t x,rt_uint16_t y,rt_uint16_t color);
rt_uint16_t LCD_ReadPoint(rt_uint16_t x,rt_uint16_t y);
void LCD_DrawLine(rt_uint16_t x1, rt_uint16_t y1, rt_uint16_t x2, rt_uint16_t y2);
void LCD_DrawLine_Color(rt_uint16_t x1, rt_uint16_t y1, rt_uint16_t x2, rt_uint16_t y2,rt_uint16_t color);
void LCD_DrowSign(uint16_t x, uint16_t y, uint16_t color);
void LCD_DrawRectangle(rt_uint16_t x1, rt_uint16_t y1, rt_uint16_t x2, rt_uint16_t y2);
void LCD_Draw_Circle(rt_uint16_t x0,rt_uint16_t y0,rt_uint8_t r);
void LCD_ShowChar(rt_uint16_t x,rt_uint16_t y,rt_uint8_t num,rt_uint8_t size,rt_uint8_t mode);
void LCD_ShowNum(rt_uint16_t x,rt_uint16_t y,rt_uint32_t num,rt_uint8_t len,rt_uint8_t size);
void LCD_ShowxNum(rt_uint16_t x,rt_uint16_t y,rt_uint32_t num,rt_uint8_t len,rt_uint8_t size,rt_uint8_t mode);
void LCD_ShowString(rt_uint16_t x,rt_uint16_t y,rt_uint16_t width,rt_uint16_t height,rt_uint8_t size,rt_uint8_t *p);
void LCD_ShowFontHZ(rt_uint16_t x, rt_uint16_t y, rt_uint8_t *cn);


#endif
