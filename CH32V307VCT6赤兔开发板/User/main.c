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
 * ����  : main
 * ����  : int
 * Input          : None
 * Return         : None
 *******************************************************************************/
int main(void) {

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����
    Delay_Init();//��ʱ������ʼ��
    USART_Printf_Init(115200);//���ڲ����ʳ�ʼ������
    lcd_init();//��ʾ����ʼ��
    LCD_SetBrightness(60);//����Ĭ����Ļ����
    lcd_clear(LGRAY); //���ñ�����ɫ
    KEY_Init(); //��ʼ��KEY
    LED_Init();//LEDָʾ�Ƴ�ʼ��
    EXTI_INT_INIT();//��ʼ�������жϺ���
    ASR01_Init();//��ʼ������ģ�����ݶ�ȡ����

    while(1) {

       nucm();//����
    }
}

