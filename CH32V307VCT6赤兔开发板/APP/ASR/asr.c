#include <ch32v30x_misc.h>
#include <lcd.h>
#include "ASR.H"

/***************
 * 接线说明：语音模块----> CH32V307模块
 *        IO1  --->D11
 *        IO2  --->D9
 *        IO3  --->D3
 *        状态检测IO --->E14
 *
 *
 * **************/
void ASR01_Init(void){//LED GPIO

            GPIO_InitTypeDef GPIO_InitStructure = {0};
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);  //打开GPIOE时钟 使能
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 |GPIO_Pin_9|GPIO_Pin_3;//选择GPIO 端口
            GPIO_InitStructure.GPIO_Mode = 0x28;       //配置输入模式 上
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //端口翻转频率
            GPIO_Init(GPIOD, &GPIO_InitStructure);                 //初始化
            GPIO_ResetBits(GPIOD, GPIO_Pin_11 |GPIO_Pin_9|GPIO_Pin_3);          //把端口默认数据设置为1

/*检测语音模块*/
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);  //打开GPIOE时钟 使能
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 ;//选择GPIO 端口
            GPIO_InitStructure.GPIO_Mode = 0x28;       //配置输入模式 上
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //端口翻转频率
            GPIO_Init(GPIOE, &GPIO_InitStructure);                 //初始化
            GPIO_SetBits(GPIOE, GPIO_Pin_14);

}

