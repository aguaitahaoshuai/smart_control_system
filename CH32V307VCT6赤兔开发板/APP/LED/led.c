#include "debug.h"
#include "LED.H"
void LED_Init(void){//LED GPIO
            GPIO_InitTypeDef GPIO_InitStructure = {0};
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);  //打开GPIOE时钟 使能
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 |GPIO_Pin_12;//选择GPIO 端口
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //配置输出模式
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //端口翻转频率
            GPIO_Init(GPIOE, &GPIO_InitStructure);                 //初始化
            GPIO_SetBits(GPIOE, GPIO_Pin_11|GPIO_Pin_12);          //把端口默认数据设置为1
}
