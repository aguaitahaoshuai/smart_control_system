#include <ch32v30x.h>
#include <ch32v30x_exti.h>
#include <ch32v30x_gpio.h>
#include <ch32v30x_misc.h>
#include <ch32v30x_rcc.h>
#include <core_riscv.h>
#include <lcd.h>
#include <stdio.h>
#include "INTEERRUPT.H"
#include "SHOWXY.H"
#include "inttypes.h"

int ONT=0;//页面记录

int num=0;//触发 key
int data=0;//功能选择
/******************
 * 等于中断 按键记录值
 */
int key_next=1;//下一页 默认 第一页
int key_set=0;//设置
int key_ok=0;//确定   2为按键触发
///////////////////////
int data_num=0;//事件转换 值


/***************
 * 接线说明：语音模块----> CH32V307模块
 *        IO1  --->D11
 *        IO2  --->D9
 *        IO3  --->D3
 * **************/

/*******************
 * 功能：页面处理 切换
 */
void PageProcessing(void){

//    switch(return_key_next()){
//
//    case 1: showXY1(); ONT=1;  break;//切换第一个页面
//    case 2: showXY2(); ONT=2;  break;//切换第二个页面  继电器
//    case 3: showXY3(); ONT=3;  break;//切换第三个页面
//    case 4: showXY4(); ONT=4;  break;//切换第四个页面
//
//    }
}

int ONT_show(void){//页面位置数据返回


return ONT;

}
//下一页面 事件触发 函数
void key_show(void){

if(num==1&&key_ok==2){data_num=1;}//确认设置页面
if(num==2&&key_ok==2){data_num=2;}//确认进入/切换下一页

    switch(data_num){

    case 1:  break;//设置页面
    case 2: key_next+=1;if(key_next==5){key_next=1;} break;//切换下一个页面

    }
    PageProcessing();
}
/******
 * 功能： 返回下一页 指令
 *
 */
int return_key_next(void){


    return key_next;
    printf("key_next:%d",key_next);
}








void show_q1(void){//选中 设置功能按键 相关
    cmcu_cua_showXY1(1);
}
void show_q2(void){//选中 设置功能按键 相关
    cmcu_cua_showXY1(0);
    cmcu_cua_showXY2(1);
}
void cmcu(void){//菜单功能选择效果页面
    switch(num){

    case 1:show_q1();break;//选择 设置
    case 2:show_q2();break;//选择 下一页
    }

}
void cut(void){//功能 下一页函数 右边按键
    num=2;
    cmcu();//切换

}
void cut_rl(void){//功能 设置函数

    num=1;//第一个
    cmcu();//切换

}
void EXTI0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI4_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI9_5_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI15_10_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

//服务中断函数
void EXTI_INT_INIT(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_13;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
      GPIO_Init(GPIOD, &GPIO_InitStructure);



  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource1);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource5);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource6);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource13);


  EXTI_InitStructure.EXTI_Line=EXTI_Line0|EXTI_Line1|EXTI_Line2|EXTI_Line3|EXTI_Line4|EXTI_Line5|EXTI_Line6|EXTI_Line13;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
    NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_Init(&NVIC_InitStructure);
}

//服务中断函数0
void EXTI0_IRQHandler(void)
{

  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
  {


    printf("Wake UP !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line0);     /* Clear Flag */
  }
}


//服务中断函数1
void EXTI1_IRQHandler(void)
{

  if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
  {

    printf("UP !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line1);     /* Clear Flag */
  }
}

//服务中断函数2
void EXTI2_IRQHandler(void)
{

  if(EXTI_GetITStatus(EXTI_Line2)!=RESET)
  {

    printf("DOWN !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line2);     /* Clear Flag */
  }
}


//服务中断函数3
void EXTI3_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line3)!=RESET)
  {

    cut();//功能 下一页函数
    printf("RIGHT !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line3);     /* Clear Flag */
  }
}

//服务中断函数4
void EXTI4_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line4)!=RESET)
  {
    printf("KEY1 !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line4);     /* Clear Flag */
  }
}

//服务中断函数5
void EXTI9_5_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line6)!=RESET)
  {

      cut_rl();
    printf("LEFT !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line6);     /* Clear Flag */
  }else {
      if(EXTI_GetITStatus(EXTI_Line5)!=RESET)
        {
          printf("KEY2 !\r\n");
          EXTI_ClearITPendingBit(EXTI_Line5);     /* Clear Flag */
        }
}
}
//ok按键
//服务中断函数6
void EXTI15_10_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line13)!=RESET)
  {
      key_ok=2;//触发
      key_show();//触发 页面
    printf("SEL !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line13);     /* Clear Flag */
  }
}







