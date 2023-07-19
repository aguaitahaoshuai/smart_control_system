#include <lcd.h>
#include <SHOWXY.H>
#include "ASR.H"
int da = 1; //主页面显示次数
//int WL=0;
void draw_table(void);
int K1 = 0;
int K2 = 0;
int K3 = 0; //继电器状态显示
int ASR_NOY = 0; //检测语言模块
int AT=0;
int AB=0;
//显示第二页面函数
void showXY_ho2(void) {

    lcd_fill(0, 0, 240, 40, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(35, 5, 32, "smart home ");
    //////////////////////

    draw_table();
    lcd_set_color(LGRAY, BLACK);
    lcd_show_string(22, 45, 24, "relay");
    lcd_show_string(35, 80, 24, "K1");
    lcd_show_string(35, 125, 24, "K2");
    lcd_show_string(35, 165, 24, "K3");
    lcd_set_color(LGRAY, BLUE);

    lcd_show_string(150, 45, 24, "data"); //数据

    if (K1 == 10) { //如果检测到K1打开就显示
        lcd_show_string(150, 80, 24, "OK");
    } else {
        lcd_show_string(150, 80, 24, "plte");
    }
    if (K2 == 10) { //如果检测到K2打开就显示
        lcd_show_string(150, 125, 24, "OK");
    } else {
        lcd_show_string(150, 125, 24, "plte");
    }
    if (K3 == 10) { //如果检测到K3打开就显示
        lcd_show_string(150, 170, 24, "OK");
    } else {
        lcd_show_string(150, 170, 24, "plte");
    }
////////////////////////////
    lcd_fill(0, 200, 240, 240, wathet);
    lcd_set_color(wathet, LGRAY);
   // lcd_show_string(10, 205, 32, "set"); //设置
    //d_show_string(160, 205, 32, "next"); //下一页
    lcd_draw_line(0, 50, 50, 70);

}

//显示第3页面函数
void showXY_ho3(void) {

//人脸识别部分
    lcd_fill(0, 0, 240, 40, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(35, 5, 32, "smart home ");
    //////////////////////
    draw_table();
    lcd_set_color(LGRAY, BLACK);
    lcd_show_string(22, 45, 24, "face");
    lcd_show_string(35, 80, 24, "R1");
    lcd_set_color(LGRAY, BLUE);

    lcd_show_string(150, 45, 24, "data"); //数据
////////////////////////////
    lcd_fill(0, 200, 240, 240, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(10, 205, 32, "set"); //设置
    lcd_show_string(160, 205, 32, "next"); //下一页
    lcd_draw_line(0, 50, 50, 70);
}
//显示第1页面函数
void show_text(void) { //显示字体
    lcd_set_color(LGRAY, BLACK);
    lcd_show_string(15, 45, 24, "sensor"); //传感器
    lcd_show_string(9, 80, 24, "humidity"); //湿度
    lcd_show_string(15, 120, 24, "temure"); //温度

    lcd_set_color(LGRAY, BLUE);

    lcd_show_string(150, 45, 24, "data"); //数据

//    if(WL==1){//ESP8266模块状态检测
//        lcd_show_string(143,165, 24, "normal");//正常
//    }else{
//        for(int i=0;i<3;i++){
//        lcd_set_color(LGRAY, RED);
//
//        lcd_show_string(143,165, 24, "       ");//异常
//        delay_ms(250);
//        lcd_show_string(143,165, 24, "anomaly");//异常
//        delay_ms(450);
//        }
    //   }
}

void draw_table(void) { //绘制表格
    for (int i = 0; i < 240; i++) {
        lcd_draw_point_color(i, 70, wathet);
        lcd_draw_point_color(i, 110, wathet);
        lcd_draw_point_color(i, 155, wathet);
        for (int a = 40; a < 200; a++) {
            lcd_draw_point_color(120, a, wathet);
        }
    }
}
void sys_show(void) { //系统启动页面
    lcd_fill(30, 70, 210, 140, wathet);
    lcd_set_color(wathet, WHITE);
    lcd_show_string(40, 90, 32, "to load...");
    delay_ms(100);
    lcd_clear(LGRAY); //系统启动完成清除屏幕显示

}

void cmcu_cua_showXY1(int bt) { //菜单选择效果显示代码 设置
    if (bt == 1) {
        lcd_fill(0, 200, 240, 240, wathet);
        lcd_set_color(wathet, GREEN);
        lcd_show_string(10, 205, 32, "set"); //设置

        //////////////取消选择显示//////////////////
        lcd_set_color(wathet, LGRAY);
        lcd_show_string(160, 205, 32, "next"); //下一页

    } else {
        lcd_fill(0, 200, 240, 240, wathet);
        lcd_set_color(wathet, LGRAY);
        lcd_show_string(10, 205, 32, "set"); //设置

    }

}
void cmcu_cua_showXY2(int bt) { //菜单选择效果显示代码  下一页

    if (bt == 1) {
        lcd_fill(0, 200, 240, 240, wathet);
        lcd_set_color(wathet, GREEN);
        lcd_show_string(160, 205, 32, "next"); //下一页
        /////////取消显示///////////
        lcd_set_color(wathet, LGRAY);
        lcd_show_string(10, 205, 32, "set");    //设置
    } else {
        lcd_fill(0, 200, 240, 240, wathet);
        lcd_set_color(wathet, LGRAY);

        lcd_show_string(160, 205, 32, "next");    //下一页
    }

}
/**************
 * 功能：智能家居 - 显示菜单
 * 返回：无
 *************/

void showXY_nucm(void) {
    // int bit=da;
    //标题
    lcd_fill(0, 0, 240, 40, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(35, 5, 32, "smart home ");
//操作按键显示

    lcd_fill(0, 200, 240, 240, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(10, 205, 32, "set");    //设置
    lcd_show_string(160, 205, 32, "next");    //下一页
    lcd_draw_line(0, 50, 50, 70);
    draw_table();    //绘制表格
    show_text();    //显示字体

}

void LED(void) { //led指示灯

    LED1(0);
    delay_ms(250);
    LED1(1);
    delay_ms(250);
    LED1(0);
    delay_ms(250);
    LED1(1);
    delay_ms(250);
}
/************
 * 显示第一个页面
 */
void showXY1(void) {
    showXY_nucm(); //智能居家 页面显示 页面初始化
}
/************
 * 显示第2个页面
 */
void showXY2(void) {
    lcd_clear(LGRAY); //设置背景颜色
    showXY_ho2(); //第二页
}
/************
 * 显示第3个页面
 */
void showXY3(void) {
    lcd_clear(LGRAY); //设置背景颜色
    showXY_ho3(); //人脸识别3

}
/************
 * 显示第4个页面
 */
void showXY4(void) {
    lcd_clear(LGRAY); //设置背景颜色
    lcd_fill(0, 0, 240, 40, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(35, 5, 32, "smart home ");
    //////////////////////
    draw_table();
    lcd_set_color(LGRAY, BLACK);
    lcd_show_string(22, 45, 24, "module");
    lcd_show_string(25, 80, 24, "ASRO1");
    lcd_show_string(25, 120, 24, "WLAN");
    lcd_set_color(LGRAY, BLUE);

    lcd_show_string(150, 45, 24, "state"); //数据
    if (ASR_NOY == 10) {
        lcd_show_string(150, 80, 24, "OK");
    } else {
        lcd_show_string(150, 80, 24, "plte");
    }
    ////////////////////////////
    lcd_fill(0, 200, 240, 240, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(10, 205, 32, "set"); //设置
    lcd_show_string(160, 205, 32, "next"); //下一页
    lcd_draw_line(0, 50, 50, 70);

}
/************
 * 功能：D 11--->0
 * 功能：D 9--->1
 * 功能：D 3--->1
 */
void key_ASR01(void) { //语音模块数据输入

    if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_11) == 1) {
        K1 = 10;
        LED2(0);
        lcd_set_color(LGRAY, BLUE);
        lcd_show_string(150, 80, 24, "    ");
        lcd_show_string(150, 80, 24, "ok");
        delay_ms(100);
    } else {
        LED2(1);
        K1 = 1;
        lcd_set_color(LGRAY, BLUE);
        lcd_show_string(150, 80, 24, "    ");
        lcd_show_string(150, 80, 24, "plte");
        delay_ms(100);
    }

    if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_9) == 1) {
        LED2(0);
        K2 = 10;
        lcd_set_color(LGRAY, BLUE);
        lcd_show_string(150, 125, 24, "    ");
        lcd_show_string(150, 125, 24, "ok");
        delay_ms(100);

    } else {
        LED2(1);
       // lcd_show_string(150, 80, 24, "plte");
        K2 = 1;
            lcd_set_color(LGRAY, BLUE);
            lcd_show_string(150, 125, 24, "    ");
            lcd_show_string(150, 125, 24, "plte");
            delay_ms(100);
    }

    if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3) == 1) {
        K3 = 10;
        LED2(0);
        lcd_set_color(LGRAY, BLUE);
        lcd_show_string(150, 170, 24, "    ");
        lcd_show_string(150, 170, 24, "ok");
        delay_ms(100);
    } else {
        LED2(1);
        K3 = 1;
          lcd_set_color(LGRAY, BLUE);
          lcd_show_string(150, 170, 24, "    ");
          lcd_show_string(150, 170, 24, "plte");
          delay_ms(100);
    }

    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_14) == 1) {
        ASR_NOY = 10;

    } else {

        ASR_NOY = 1;

    }
}
/***************
 * 功能说明：次程序 处理数据
 * 时间：2023年5月19日16:25:53
 * **************/
void nucm(void) {
    sys_show(); //系统启动加载页面显示
    showXY_nucm(); //智能居家 页面显示 页面初始化
    showXY2();
    while(1) {
       // LED2(0);
        key_ASR01(); //语音模块数据输入
       // LED2(1);


    }
}
