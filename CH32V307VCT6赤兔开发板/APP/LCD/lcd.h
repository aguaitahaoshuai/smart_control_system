    /********************************** (C) COPYRIGHT *******************************
* File Name          : lcd.h
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : This file contains the headers of the TFTLCD.
*******************************************************************************/
#ifndef __LCD_H
#define __LCD_H	

#include"debug.h"
#include"stdlib.h"

#define  LCD_CMD         ((u32)0x6001FFFF)
#define  LCD_DATA        ((u32)0x60020000)

/* PWM Output Mode Definition */
#define PWM_MODE1   0
#define PWM_MODE2   1

/* PWM Output Mode Selection */
#define PWM_MODE PWM_MODE1
//#define PWM_MODE PWM_MODE2


#define  delay_ms(x)  Delay_Ms(x)
#define  delay_us(x)  Delay_Us(x)



#define LCD_W 240
#define LCD_H 240

//POINT_COLOR
#define WHITE            0xFFFF//白色
#define BLACK            0x0000//黑色
#define BLUE             0x001F//蓝色
#define BRED             0XF81F//紫色
#define GRED             0XFFE0//黄色
#define GBLUE            0X07FF//浅蓝色
#define RED              0xF800//红色
#define MAGENTA          0xF81F// 品红
#define GREEN            0x07E0//绿色
#define CYAN             0x7FFF//蓝绿色
#define YELLOW           0xFFE0//黄色
#define BROWN            0XBC40//浅黄色
#define BRRED            0XFC07//浅橙色
#define GRAY             0X8430//灰色
#define GRAY175          0XAD75
#define GRAY151          0X94B2
#define GRAY187          0XBDD7
#define GRAY240          0XF79E//白灰色
#define LGRAY            0XC618//浅灰色
#define wathet           0x033c//浅蓝色


void lcd_clear(u16 color);//设置背景颜色
void lcd_address_set(u16 x1, u16 y1, u16 x2, u16 y2);
void lcd_set_color(u16 back, u16 fore);//设置字体背景颜色

void lcd_draw_point(u16 x, u16 y);
void lcd_draw_point_color(u16 x, u16 y, u16 color);
void lcd_draw_circle(u16 x0, u16 y0, u8 r);//画一个圆
void lcd_draw_line(u16 x1, u16 y1, u16 x2, u16 y2);//画一个线
void lcd_draw_rectangle(u16 x1, u16 y1, u16 x2, u16 y2);//画一个长方形
void lcd_fill(u16 x_start, u16 y_start, u16 x_end, u16 y_end, u16 color);

void lcd_show_num(u16 x, u16 y, u32 num, u8 len, u32 size);
void lcd_show_string(u16 x, u16 y, u32 size, const char *fmt, ...);//显示字符
void lcd_show_image(u16 x, u16 y, u16 length, u16 wide, const u8 *p);

void lcd_init(void);
void LCD_SetBrightness(u8 brightness);

void lcd_enter_sleep(void);
void lcd_exit_sleep(void);
void lcd_display_on(void);
void lcd_display_off(void);
void LCD_SetBrightness(u8 brightness);
#endif  










