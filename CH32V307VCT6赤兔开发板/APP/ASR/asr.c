#include <ch32v30x_misc.h>
#include <lcd.h>
#include "ASR.H"

/***************
 * ����˵��������ģ��----> CH32V307ģ��
 *        IO1  --->D11
 *        IO2  --->D9
 *        IO3  --->D3
 *        ״̬���IO --->E14
 *
 *
 * **************/
void ASR01_Init(void){//LED GPIO

            GPIO_InitTypeDef GPIO_InitStructure = {0};
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);  //��GPIOEʱ�� ʹ��
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 |GPIO_Pin_9|GPIO_Pin_3;//ѡ��GPIO �˿�
            GPIO_InitStructure.GPIO_Mode = 0x28;       //��������ģʽ ��
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�˿ڷ�תƵ��
            GPIO_Init(GPIOD, &GPIO_InitStructure);                 //��ʼ��
            GPIO_ResetBits(GPIOD, GPIO_Pin_11 |GPIO_Pin_9|GPIO_Pin_3);          //�Ѷ˿�Ĭ����������Ϊ1

/*�������ģ��*/
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);  //��GPIOEʱ�� ʹ��
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 ;//ѡ��GPIO �˿�
            GPIO_InitStructure.GPIO_Mode = 0x28;       //��������ģʽ ��
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�˿ڷ�תƵ��
            GPIO_Init(GPIOE, &GPIO_InitStructure);                 //��ʼ��
            GPIO_SetBits(GPIOE, GPIO_Pin_14);

}

