#include "debug.h"
#include "LED.H"
void LED_Init(void){//LED GPIO
            GPIO_InitTypeDef GPIO_InitStructure = {0};
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);  //��GPIOEʱ�� ʹ��
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 |GPIO_Pin_12;//ѡ��GPIO �˿�
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //�������ģʽ
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�˿ڷ�תƵ��
            GPIO_Init(GPIOE, &GPIO_InitStructure);                 //��ʼ��
            GPIO_SetBits(GPIOE, GPIO_Pin_11|GPIO_Pin_12);          //�Ѷ˿�Ĭ����������Ϊ1
}
