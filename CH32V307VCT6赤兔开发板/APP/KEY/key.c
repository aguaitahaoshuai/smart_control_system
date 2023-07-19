#include "debug.h"
#include "KEY.H"

void KEY_Init(void) { //LED GPIO
    GPIO_InitTypeDef GPIO_InitStructure = { 0 };
    RCC_APB2PeriphClockCmd(
    RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOA, ENABLE); //��GPIOEʱ�� ʹ��

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3
            | GPIO_Pin_4 | GPIO_Pin_5; //ѡ��GPIO �˿�
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�˿ڷ�תƵ��
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //��ʼ��
    GPIO_SetBits(GPIOE,
    GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5); //�Ѷ˿�Ĭ����������Ϊ1
    ///////////////////////////////////////////////////////////////////////
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_13;          //ѡ��GPIO �˿�
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�˿ڷ�תƵ��
    GPIO_Init(GPIOD, &GPIO_InitStructure);                 //��ʼ��
    GPIO_SetBits(GPIOD, GPIO_Pin_6 | GPIO_Pin_13);          //�Ѷ˿�Ĭ����������Ϊ1
    //////////////////////////////////////////////////
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;          //ѡ��GPIO �˿�
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�˿ڷ�תƵ��
    GPIO_Init(GPIOA, &GPIO_InitStructure);                 //��ʼ��
    GPIO_SetBits(GPIOA, GPIO_Pin_0);          //�Ѷ˿�Ĭ����������Ϊ1


   //////////////////////////����ģ����Գ���///////////////
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;          //ѡ��GPIO �˿�
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //�˿ڷ�תƵ��
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //��ʼ��
    GPIO_SetBits(GPIOE, GPIO_Pin_14);          //�Ѷ˿�Ĭ����������Ϊ1


}
//��ȡkey
int KEY(void) {
    int key = 0;
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_1) != 1) {
        delay_ms(10);          //������������
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_1) == 0) {

            key = 1;
        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==0);
    //���������ּ��
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) != 1) {
        delay_ms(10);          //������������
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == 0) {
            key = 2;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0);
    //���������ּ��
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) != 1) {
        delay_ms(10);          //������������
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == 0) {

            key = 3;
        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0);
    //���������ּ��

    if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6) != 1) {
        delay_ms(10);          //������������
        if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6) == 0) {
            key = 4;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)==0);
    //���������ּ��
    if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_13) != 1) {
        delay_ms(10);          //������������
        if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_13) == 0) {
            key = 5;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_13)==0);
    //���������ּ��
    ////////////////////key����3//////////////////
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) != 1) {
        delay_ms(10);          //������������
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == 0) {
            key = 6;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0);

    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5) != 1) {
        delay_ms(10);          //������������
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5) == 0) {
            key = 7;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)==0);

    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 1) {
        delay_ms(10);          //������������
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0) {
            key = 8;
        }
    }
    while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0);

    return key;

}
