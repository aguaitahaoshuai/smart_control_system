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
#ifndef _KEY_H
#define _KEY_H
#include "debug.h"
#define  delay_ms(x)  Delay_Ms(x)
#define  delay_us(x)  Delay_Us(x)

void KEY_Init(void);//LED GPIOº¯Êý
int KEY(void);


#endif /* __CH32V30x_IT_H */


