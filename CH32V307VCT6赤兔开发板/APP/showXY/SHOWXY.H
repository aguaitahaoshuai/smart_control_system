/********************************** (C)  ³ÌÐòshowXY *******************************
* File Name          : ch32v30x_it.h
* Author             : WCH
* Version            : V1.0.0
* Date               : 2023/05/07
* Description        :sonlin
*********************************************************************************
*
*
*******************************************************************************/
#ifndef _SHOWXY_H
#define _SHOWXY_H
#define  LED1(x) GPIO_WriteBit(GPIOE,GPIO_Pin_11,x)//LED1
#define  LED2(x) GPIO_WriteBit(GPIOE,GPIO_Pin_12,x)//LED2
void LED(void);
void nucm(void);
void showXY_ho2(void);
void cmcu_cua_showXY1(int bt);
void cmcu_cua_showXY2(int bt);
void showXY1(void);
void showXY2(void);
void showXY3(void);
void showXY4(void);

#endif /* __CH32V30x_IT_H */


