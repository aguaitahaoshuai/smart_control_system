#include "debug.h"
#include "KEY.H"

void KEY_Init(void) { //LED GPIO
    GPIO_InitTypeDef GPIO_InitStructure = { 0 };
    RCC_APB2PeriphClockCmd(
    RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOA, ENABLE); //打开GPIOE时钟 使能

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3
            | GPIO_Pin_4 | GPIO_Pin_5; //选择GPIO 端口
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //端口翻转频率
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //初始化
    GPIO_SetBits(GPIOE,
    GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5); //把端口默认数据设置为1
    ///////////////////////////////////////////////////////////////////////
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_13;          //选择GPIO 端口
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //端口翻转频率
    GPIO_Init(GPIOD, &GPIO_InitStructure);                 //初始化
    GPIO_SetBits(GPIOD, GPIO_Pin_6 | GPIO_Pin_13);          //把端口默认数据设置为1
    //////////////////////////////////////////////////
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;          //选择GPIO 端口
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //端口翻转频率
    GPIO_Init(GPIOA, &GPIO_InitStructure);                 //初始化
    GPIO_SetBits(GPIOA, GPIO_Pin_0);          //把端口默认数据设置为1


   //////////////////////////语音模块测试程序///////////////
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;          //选择GPIO 端口
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //端口翻转频率
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //初始化
    GPIO_SetBits(GPIOE, GPIO_Pin_14);          //把端口默认数据设置为1


}
//获取key
int KEY(void) {
    int key = 0;
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_1) != 1) {
        delay_ms(10);          //消除按键抖动
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_1) == 0) {

            key = 1;
        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==0);
    //按键的松手检测
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) != 1) {
        delay_ms(10);          //消除按键抖动
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == 0) {
            key = 2;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0);
    //按键的松手检测
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) != 1) {
        delay_ms(10);          //消除按键抖动
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == 0) {

            key = 3;
        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0);
    //按键的松手检测

    if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6) != 1) {
        delay_ms(10);          //消除按键抖动
        if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6) == 0) {
            key = 4;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)==0);
    //按键的松手检测
    if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_13) != 1) {
        delay_ms(10);          //消除按键抖动
        if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_13) == 0) {
            key = 5;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_13)==0);
    //按键的松手检测
    ////////////////////key按键3//////////////////
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) != 1) {
        delay_ms(10);          //消除按键抖动
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == 0) {
            key = 6;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0);

    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5) != 1) {
        delay_ms(10);          //消除按键抖动
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5) == 0) {
            key = 7;

        }
    }
    while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)==0);

    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != 1) {
        delay_ms(10);          //消除按键抖动
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0) {
            key = 8;
        }
    }
    while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0);

    return key;

}
