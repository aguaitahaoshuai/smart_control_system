/********************************** (C) LED ³ÌÐò *******************************
* File Name          : ch32v30x_it.h
* Author             : WCH
* Version            : V1.0.0
* Date               : 2023/05/07
* Description        :sonlin
*********************************************************************************
*
*
*******************************************************************************/
#ifndef _LED_H
#define _LED_H
#include "debug.h"
#define  LED1(x) GPIO_WriteBit(GPIOE,GPIO_Pin_11,x)//LED1
#define  LED2(x) GPIO_WriteBit(GPIOE,GPIO_Pin_12,x)//LED2
void LED_Init(void);//LED GPIOº¯Êý



#endif /* __CH32V30x_IT_H */


