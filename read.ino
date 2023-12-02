
/*==================================*/
int getFC(void) {                                   // Вывод количества файлов в системе (из кода гайвера)
  int count = 0;                                    // Счетчик
  Dir root = LittleFS.openDir("/");                 // Открываем директорию (корень)
  while (root.next()) {                             // Шагаем по директории
    File file = root.openFile("r");                 // Открываем файл для чтения
    if (file) count++;                              // Если с файлом все ОК - инкремент
    file.close();                                   // Закрываем файл
  } return count;                                   // Возвращаем количество
}

/* === перемещение в меню № 1(середнее) ===*/
void keys(void){                                 
 keypressed = myESPboy.getKeys();                  
 Serial.print(" file № ");
 Serial.println(menu);
 
 if (keypressed){      
    myESPboy.tft.fillScreen(TFT_BLACK);
    if (keypressed&PAD_UP){
      if (menu >= 2) { menu = menu - 1;}
    }
    
    if (keypressed&PAD_DOWN){ 
     if (menu < mxc){menu = menu + 1;}
    }
    /*== вкладки в меню*/
    if (keypressed&PAD_LEFT){
      if (menuH > 0) { menuH = menuH - 1;}
    }
    
    if (keypressed&PAD_RIGHT){ 
     if (menuH <= 1){ menuH = menuH + 1; }
    }
    
    }

}


/* ========= чтение файлов ======== */
void readFile(int nom)   
{   
   
File file = LittleFS.open(makeName(origName,menu), "r");
String readr;
if(!file)                                     //цел ли файл                                  
{
Serial.println(" Data Error ");               //выводит ошибку
myESPboy.tft.fillScreen(TFT_BLACK);
myESPboy.tft.setCursor(1,20);
myESPboy.tft.print(" Data Error "); 
myESPboy.myLED.setRGB(255, 0, 0); 
delay(1000);
myESPboy.myLED.setRGB(0, 0, 0); 
return;                                       //потом выходит
}

myESPboy.tft.fillScreen(TFT_BLACK);
myESPboy.tft.setCursor(5,5);
TextColor(txtC);                              //установка цвета текста
// печать
while(file.available())                       
{
  myESPboy.tft.write(file.read());            //чтение
  }


                                              // закрытие
delay(1000);
while(1){
  delay(500);
   keypressed = myESPboy.getKeys();   
   if (keypressed){ 
     if (keypressed&PAD_ESC){ return; }    
   }   
   } 
file.close();     
myESPboy.tft.fillScreen(TFT_BLACK);   
}

                      

/* ========= создание имени файла ============*/
String makeName(String orig, int m) 
{
  String chanName = orig + m + ".txt";
  Serial.println(chanName);
  return chanName;
}

  
