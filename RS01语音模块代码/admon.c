#include "asr.h"
#include "setup.h"
#include "myLib/luxiaoban.h"

uint32_t snid;
DHTxx _component(9);
QueueHandle_t play = xQueueCreate(5,4);
float temp = 255;
uint8_t hum = 255;
uint32_t var = 0;
uint32_t ser_rec = 0;

//{ID:250,keyword:"命令词",ASR:"最大音量",ASRTO:"音量调整到最大"}
//{ID:251,keyword:"命令词",ASR:"中等音量",ASRTO:"音量调整到中等"}
//{ID:252,keyword:"命令词",ASR:"最小音量",ASRTO:"音量调整到最小"}
//{playid:10001,voice:欢迎使用开拓队开发智能居家控制平台，我的名字叫小拓，有事请吩咐}
//{playid:10002,voice:我退下了，用小拓唤醒我}
void audio_play(){
  while (1) {
    if(xQueueReceive(play,&ser_rec,0)){
      if(ser_rec == 1)
      {
        temp = _component.read_temperature();
        luxiaoban_speech(temp, 255);
      }else if(ser_rec == 2){
        temp = _component.read_temperature();
        hum = _component.readHumidity();
        luxiaoban_speech(temp, hum);
      }
    }
    delay(10);
  }
  vTaskDelete(NULL);
}
//{ID:1,keyword:"命令词",ASR:"我是一",ASRTO:"一"}
//{ID:2,keyword:"命令词",ASR:"我是二",ASRTO:"二"}
//{ID:3,keyword:"命令词",ASR:"我是三",ASRTO:"三"}
//{ID:4,keyword:"命令词",ASR:"我是四",ASRTO:"四"}
//{ID:5,keyword:"命令词",ASR:"我是五",ASRTO:"五"}
//{ID:6,keyword:"命令词",ASR:"我是六",ASRTO:"六"}
//{ID:7,keyword:"命令词",ASR:"我是七",ASRTO:"七"}
//{ID:8,keyword:"命令词",ASR:"我是八",ASRTO:"八"}
//{ID:9,keyword:"命令词",ASR:"我是九",ASRTO:"九"}
//{ID:10,keyword:"命令词",ASR:"我是十",ASRTO:"十"}
//{ID:11,keyword:"命令词",ASR:"我是百",ASRTO:"百"}
//{ID:12,keyword:"命令词",ASR:"我是千",ASRTO:"千"}
//{ID:13,keyword:"命令词",ASR:"我是摄氏度",ASRTO:"摄氏度"}
//{ID:24,keyword:"命令词",ASR:"我是点",ASRTO:"点"}
//{ID:25,keyword:"命令词",ASR:"当前温度唯",ASRTO:"温度唯"}
//{ID:26,keyword:"命令词",ASR:"湿度百分之",ASRTO:"湿度百分之"}
//{ID:27,keyword:"命令词",ASR:"我是零",ASRTO:"零"}
//{ID:28,keyword:"命令词",ASR:"当前温度唯零下",ASRTO:"温度唯零下"}
void ASR_CODE()
{
  //{speak:丫丫-可爱女童,vol:10,speed:10,platform:baidu}
  //{ID:500,keyword:"唤醒词",ASR:"我们的口号是什么",ASRTO:"科技改变生活，创新成就精彩"}
  //{ID:501,keyword:"唤醒词",ASR:"你是谁",ASRTO:"我是您的智能管家"}
  //{ID:502,keyword:"唤醒词",ASR:"你会做什么",ASRTO:"我会帮主人管理家庭电器设备，比如打开灯泡等等操作"}
  //{ID:503,keyword:"唤醒词",ASR:"你会做什么",ASRTO:"我会帮主人管理家庭电器设备，比如打开灯泡等等操作"}
  //{ID:504,keyword:"唤醒词",ASR:"小拓同学",ASRTO:"我在呢"}
  //{ID:505,keyword:"唤醒词",ASR:"小拓",ASRTO:"你好 主人"}
  //{ID:506,keyword:"唤醒词",ASR:"小拓",ASRTO:"你好 主人"}
  //{ID:507,keyword:"唤醒词",ASR:"你好小拓",ASRTO:"请吩咐"}
  //{ID:508,keyword:"命令词",ASR:"开灯",ASRTO:"灯已打开"}
  if(snid == 508){
    luxiaoban_digital_write(0,1);
  }
  //{ID:509,keyword:"命令词",ASR:"关灯",ASRTO:"灯已关闭"}
  if(snid == 509){
    luxiaoban_digital_write(0,0);
  }
  //{ID:510,keyword:"命令词",ASR:"我回来了",ASRTO:"主人欢迎回家，小拓已经自动帮您关闭离家模式，主人休息一下吧"}
  if(snid == 510){
    luxiaoban_digital_write(1,0);
  }
  //{ID:511,keyword:"命令词",ASR:"打开离家模式",ASRTO:"已打开离家模式"}
  if(snid == 511){
    luxiaoban_digital_write(1,1);
  }
  //{ID:512,keyword:"命令词",ASR:"关闭离家模式",ASRTO:"离家模式已关闭"}
  if(snid == 512){
    luxiaoban_digital_write(1,0);
  }
  //{ID:513,keyword:"命令词",ASR:"打开窗帘",ASRTO:"已打开窗帘"}
  if(snid == 513){
    luxiaoban_digital_write(2,1);
  }
  //{ID:514,keyword:"命令词",ASR:"关闭窗帘",ASRTO:"已关闭窗帘"}
  if(snid == 514){
    luxiaoban_digital_write(2,0);
  }
  //{ID:515,keyword:"命令词",ASR:"当前温湿度",ASRTO:"当前"}
  if(snid == 515){
    ser_rec = 2;
    xQueueSend(play,&ser_rec,0);
  }
  //{ID:0,keyword:"命令词",ASR:"退下",ASRTO:"好的主人，小拓30秒以后自动退出"}
}

void setup()
{
  luxiaoban_digital_write_all(0);
  _component.init();
  xTaskCreate(audio_play,"audio_play",256,NULL,4,NULL);
}
