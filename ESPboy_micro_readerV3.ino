                                              //библиотеки для ESPboy
#include "lib/ESPboyInit.h"
#include "lib/ESPboyInit.cpp"
ESPboyInit myESPboy;
#include <LittleFS.h>                   
#include <Wire.h>                       

                                              //для wifi загрузчика 
/*========== wifi =========*/
#include <GyverPortal.h>  
GyverPortal ui(&LittleFS);    

#define ssid     "ESPboy Wi-Fi file meneger"  //имя сети
#define password "11111111"                   //пароль

/*=========== переменные для чтения ===========*/
int8_t isDAC;
static uint8_t keypressed;
String origName = "/test" ;
/*=========== основные переменные  ===========*/
int txtC = 0;                                 //отвечает за цвет текста при выводе(внутри файла) 
                                              // диапозон 0 - 4 
 
int mxc;                                      //максимально колличество файлов 
int menu = 1;                                 // курсор в меню выбора файлов
int menuH = 1;                                // 0 - левая страница, 1 - файлы для чтения, 2 - цвета текста

int del = 200;                                //задержка(требуется в одном местечке)
/*============================================*/


void setup(){
  myESPboy.begin("micro reader by Alex");
  isDAC = myESPboy.mcp.writeDAC(4096, false);
  Serial.begin(115200);
  LittleFS.begin();   
  if(!LittleFS.begin()){ Serial.println(" Error LittleFS "); }   
   myESPboy.myLED.off(); 
  mxc = getFC();
}


void loop() {          
keys();                                     //отвечает за перемещение
mxc = getFC();                              //проверка на изменение колличества файлов
menuHoriz(menuH);                          
}
