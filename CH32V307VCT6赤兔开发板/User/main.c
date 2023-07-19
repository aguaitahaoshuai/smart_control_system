#include <ch32v30x_misc.h>
#include <debug.h>
#include <KEY.H>
#include <lcd.h>
#include <LED.H>
#include <stdio.h>
#include <system_ch32v30x.h>
#include <SHOWXY.H>
#include  "INTEERRUPT.H"
#include "ASR.H"
/*******************************************************************************
 * 功能  : main
 * 返回  : int
 * Input          : None
 * Return         : None
 *******************************************************************************/
int main(void) {

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//分组
    Delay_Init();//延时函数初始化
    USART_Printf_Init(115200);//串口波特率初始化设置
    lcd_init();//显示器初始化
    LCD_SetBrightness(60);//设置默认屏幕亮度
    lcd_clear(LGRAY); //设置背景颜色
    KEY_Init(); //初始化KEY
    LED_Init();//LED指示灯初始化
    EXTI_INT_INIT();//初始化服务中断函数
    ASR01_Init();//初始化语言模块数据读取函数

    while(1) {

       nucm();//进入
    }
}

