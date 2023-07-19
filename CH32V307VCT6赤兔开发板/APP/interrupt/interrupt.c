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

int ONT=0;//ҳ���¼

int num=0;//���� key
int data=0;//����ѡ��
/******************
 * �����ж� ������¼ֵ
 */
int key_next=1;//��һҳ Ĭ�� ��һҳ
int key_set=0;//����
int key_ok=0;//ȷ��   2Ϊ��������
///////////////////////
int data_num=0;//�¼�ת�� ֵ


/***************
 * ����˵��������ģ��----> CH32V307ģ��
 *        IO1  --->D11
 *        IO2  --->D9
 *        IO3  --->D3
 * **************/

/*******************
 * ���ܣ�ҳ�洦�� �л�
 */
void PageProcessing(void){

//    switch(return_key_next()){
//
//    case 1: showXY1(); ONT=1;  break;//�л���һ��ҳ��
//    case 2: showXY2(); ONT=2;  break;//�л��ڶ���ҳ��  �̵���
//    case 3: showXY3(); ONT=3;  break;//�л�������ҳ��
//    case 4: showXY4(); ONT=4;  break;//�л����ĸ�ҳ��
//
//    }
}

int ONT_show(void){//ҳ��λ�����ݷ���


return ONT;

}
//��һҳ�� �¼����� ����
void key_show(void){

if(num==1&&key_ok==2){data_num=1;}//ȷ������ҳ��
if(num==2&&key_ok==2){data_num=2;}//ȷ�Ͻ���/�л���һҳ

    switch(data_num){

    case 1:  break;//����ҳ��
    case 2: key_next+=1;if(key_next==5){key_next=1;} break;//�л���һ��ҳ��

    }
    PageProcessing();
}
/******
 * ���ܣ� ������һҳ ָ��
 *
 */
int return_key_next(void){


    return key_next;
    printf("key_next:%d",key_next);
}








void show_q1(void){//ѡ�� ���ù��ܰ��� ���
    cmcu_cua_showXY1(1);
}
void show_q2(void){//ѡ�� ���ù��ܰ��� ���
    cmcu_cua_showXY1(0);
    cmcu_cua_showXY2(1);
}
void cmcu(void){//�˵�����ѡ��Ч��ҳ��
    switch(num){

    case 1:show_q1();break;//ѡ�� ����
    case 2:show_q2();break;//ѡ�� ��һҳ
    }

}
void cut(void){//���� ��һҳ���� �ұ߰���
    num=2;
    cmcu();//�л�

}
void cut_rl(void){//���� ���ú���

    num=1;//��һ��
    cmcu();//�л�

}
void EXTI0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI4_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI9_5_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI15_10_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

//�����жϺ���
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

//�����жϺ���0
void EXTI0_IRQHandler(void)
{

  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
  {


    printf("Wake UP !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line0);     /* Clear Flag */
  }
}


//�����жϺ���1
void EXTI1_IRQHandler(void)
{

  if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
  {

    printf("UP !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line1);     /* Clear Flag */
  }
}

//�����жϺ���2
void EXTI2_IRQHandler(void)
{

  if(EXTI_GetITStatus(EXTI_Line2)!=RESET)
  {

    printf("DOWN !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line2);     /* Clear Flag */
  }
}


//�����жϺ���3
void EXTI3_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line3)!=RESET)
  {

    cut();//���� ��һҳ����
    printf("RIGHT !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line3);     /* Clear Flag */
  }
}

//�����жϺ���4
void EXTI4_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line4)!=RESET)
  {
    printf("KEY1 !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line4);     /* Clear Flag */
  }
}

//�����жϺ���5
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
//ok����
//�����жϺ���6
void EXTI15_10_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line13)!=RESET)
  {
      key_ok=2;//����
      key_show();//���� ҳ��
    printf("SEL !\r\n");
    EXTI_ClearITPendingBit(EXTI_Line13);     /* Clear Flag */
  }
}







