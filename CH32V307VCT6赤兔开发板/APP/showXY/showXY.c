#include <lcd.h>
#include <SHOWXY.H>
#include "ASR.H"
int da = 1; //��ҳ����ʾ����
//int WL=0;
void draw_table(void);
int K1 = 0;
int K2 = 0;
int K3 = 0; //�̵���״̬��ʾ
int ASR_NOY = 0; //�������ģ��
int AT=0;
int AB=0;
//��ʾ�ڶ�ҳ�溯��
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

    lcd_show_string(150, 45, 24, "data"); //����

    if (K1 == 10) { //�����⵽K1�򿪾���ʾ
        lcd_show_string(150, 80, 24, "OK");
    } else {
        lcd_show_string(150, 80, 24, "plte");
    }
    if (K2 == 10) { //�����⵽K2�򿪾���ʾ
        lcd_show_string(150, 125, 24, "OK");
    } else {
        lcd_show_string(150, 125, 24, "plte");
    }
    if (K3 == 10) { //�����⵽K3�򿪾���ʾ
        lcd_show_string(150, 170, 24, "OK");
    } else {
        lcd_show_string(150, 170, 24, "plte");
    }
////////////////////////////
    lcd_fill(0, 200, 240, 240, wathet);
    lcd_set_color(wathet, LGRAY);
   // lcd_show_string(10, 205, 32, "set"); //����
    //d_show_string(160, 205, 32, "next"); //��һҳ
    lcd_draw_line(0, 50, 50, 70);

}

//��ʾ��3ҳ�溯��
void showXY_ho3(void) {

//����ʶ�𲿷�
    lcd_fill(0, 0, 240, 40, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(35, 5, 32, "smart home ");
    //////////////////////
    draw_table();
    lcd_set_color(LGRAY, BLACK);
    lcd_show_string(22, 45, 24, "face");
    lcd_show_string(35, 80, 24, "R1");
    lcd_set_color(LGRAY, BLUE);

    lcd_show_string(150, 45, 24, "data"); //����
////////////////////////////
    lcd_fill(0, 200, 240, 240, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(10, 205, 32, "set"); //����
    lcd_show_string(160, 205, 32, "next"); //��һҳ
    lcd_draw_line(0, 50, 50, 70);
}
//��ʾ��1ҳ�溯��
void show_text(void) { //��ʾ����
    lcd_set_color(LGRAY, BLACK);
    lcd_show_string(15, 45, 24, "sensor"); //������
    lcd_show_string(9, 80, 24, "humidity"); //ʪ��
    lcd_show_string(15, 120, 24, "temure"); //�¶�

    lcd_set_color(LGRAY, BLUE);

    lcd_show_string(150, 45, 24, "data"); //����

//    if(WL==1){//ESP8266ģ��״̬���
//        lcd_show_string(143,165, 24, "normal");//����
//    }else{
//        for(int i=0;i<3;i++){
//        lcd_set_color(LGRAY, RED);
//
//        lcd_show_string(143,165, 24, "       ");//�쳣
//        delay_ms(250);
//        lcd_show_string(143,165, 24, "anomaly");//�쳣
//        delay_ms(450);
//        }
    //   }
}

void draw_table(void) { //���Ʊ��
    for (int i = 0; i < 240; i++) {
        lcd_draw_point_color(i, 70, wathet);
        lcd_draw_point_color(i, 110, wathet);
        lcd_draw_point_color(i, 155, wathet);
        for (int a = 40; a < 200; a++) {
            lcd_draw_point_color(120, a, wathet);
        }
    }
}
void sys_show(void) { //ϵͳ����ҳ��
    lcd_fill(30, 70, 210, 140, wathet);
    lcd_set_color(wathet, WHITE);
    lcd_show_string(40, 90, 32, "to load...");
    delay_ms(100);
    lcd_clear(LGRAY); //ϵͳ������������Ļ��ʾ

}

void cmcu_cua_showXY1(int bt) { //�˵�ѡ��Ч����ʾ���� ����
    if (bt == 1) {
        lcd_fill(0, 200, 240, 240, wathet);
        lcd_set_color(wathet, GREEN);
        lcd_show_string(10, 205, 32, "set"); //����

        //////////////ȡ��ѡ����ʾ//////////////////
        lcd_set_color(wathet, LGRAY);
        lcd_show_string(160, 205, 32, "next"); //��һҳ

    } else {
        lcd_fill(0, 200, 240, 240, wathet);
        lcd_set_color(wathet, LGRAY);
        lcd_show_string(10, 205, 32, "set"); //����

    }

}
void cmcu_cua_showXY2(int bt) { //�˵�ѡ��Ч����ʾ����  ��һҳ

    if (bt == 1) {
        lcd_fill(0, 200, 240, 240, wathet);
        lcd_set_color(wathet, GREEN);
        lcd_show_string(160, 205, 32, "next"); //��һҳ
        /////////ȡ����ʾ///////////
        lcd_set_color(wathet, LGRAY);
        lcd_show_string(10, 205, 32, "set");    //����
    } else {
        lcd_fill(0, 200, 240, 240, wathet);
        lcd_set_color(wathet, LGRAY);

        lcd_show_string(160, 205, 32, "next");    //��һҳ
    }

}
/**************
 * ���ܣ����ܼҾ� - ��ʾ�˵�
 * ���أ���
 *************/

void showXY_nucm(void) {
    // int bit=da;
    //����
    lcd_fill(0, 0, 240, 40, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(35, 5, 32, "smart home ");
//����������ʾ

    lcd_fill(0, 200, 240, 240, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(10, 205, 32, "set");    //����
    lcd_show_string(160, 205, 32, "next");    //��һҳ
    lcd_draw_line(0, 50, 50, 70);
    draw_table();    //���Ʊ��
    show_text();    //��ʾ����

}

void LED(void) { //ledָʾ��

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
 * ��ʾ��һ��ҳ��
 */
void showXY1(void) {
    showXY_nucm(); //���ܾӼ� ҳ����ʾ ҳ���ʼ��
}
/************
 * ��ʾ��2��ҳ��
 */
void showXY2(void) {
    lcd_clear(LGRAY); //���ñ�����ɫ
    showXY_ho2(); //�ڶ�ҳ
}
/************
 * ��ʾ��3��ҳ��
 */
void showXY3(void) {
    lcd_clear(LGRAY); //���ñ�����ɫ
    showXY_ho3(); //����ʶ��3

}
/************
 * ��ʾ��4��ҳ��
 */
void showXY4(void) {
    lcd_clear(LGRAY); //���ñ�����ɫ
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

    lcd_show_string(150, 45, 24, "state"); //����
    if (ASR_NOY == 10) {
        lcd_show_string(150, 80, 24, "OK");
    } else {
        lcd_show_string(150, 80, 24, "plte");
    }
    ////////////////////////////
    lcd_fill(0, 200, 240, 240, wathet);
    lcd_set_color(wathet, LGRAY);
    lcd_show_string(10, 205, 32, "set"); //����
    lcd_show_string(160, 205, 32, "next"); //��һҳ
    lcd_draw_line(0, 50, 50, 70);

}
/************
 * ���ܣ�D 11--->0
 * ���ܣ�D 9--->1
 * ���ܣ�D 3--->1
 */
void key_ASR01(void) { //����ģ����������

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
 * ����˵�����γ��� ��������
 * ʱ�䣺2023��5��19��16:25:53
 * **************/
void nucm(void) {
    sys_show(); //ϵͳ��������ҳ����ʾ
    showXY_nucm(); //���ܾӼ� ҳ����ʾ ҳ���ʼ��
    showXY2();
    while(1) {
       // LED2(0);
        key_ASR01(); //����ģ����������
       // LED2(1);


    }
}
