
/*======== отрисовка меню =========*/
void Menu(int m){
int numF;  
myESPboy.tft.setTextSize(1);

  // печать колличество найденых файлов
  myESPboy.tft.setTextColor(TFT_YELLOW);    
  myESPboy.tft.setCursor(10,6);
  myESPboy.tft.print("files found ");
  myESPboy.tft.setCursor(1,6);
  myESPboy.tft.print(mxc); 
  /*========================================*/ 
  myESPboy.tft.setTextColor(TFT_GREEN);  
  myESPboy.tft.setCursor(1,25);
  myESPboy.tft.print("OPEN FLILE ");
  myESPboy.tft.setCursor(3,40);
  myESPboy.tft.print(makeName(origName,m));
  myESPboy.tft.setTextColor(TFT_YELLOW);
  myESPboy.tft.setCursor(65,25);
  myESPboy.tft.print(m);
  delay(100);
  /*============= опрос кнопок ==============*/ 
    
  keypressed = myESPboy.getKeys();
   if (keypressed){      
    myESPboy.tft.fillScreen(TFT_BLACK);
    if (keypressed&PAD_ACT){
      Serial.println(" A is press(start reading ");
      readFile(menu);   //прочитать файл
     }
     
    if (keypressed&PAD_ESC){
      Serial.print(" Esc is press");
      delay(del);
   }
   myESPboy.tft.fillScreen(TFT_BLACK);
   } 
  }
  
/*========== меню по горизонтали ========*/
void menuHoriz(int menH){         
if(menH == 0){uploadMenu();}
if(menH == 1){Menu(menu);}
if(menH == 2){colorMenu(); }  
}

/* ========== загрузчик файлов =========*/
void uploadMenu()
{ 
 enterToWifiMenu();        
 myESPboy.tft.fillScreen(TFT_BLACK);         
  }      

/*========== менеджер цветов =========*/
void colorMenu()
{
  Serial.print(" color "); 
  Serial.println(txtC);                       //вывод цвета в Serial
  myESPboy.tft.setTextSize(2);             
  TextColor(txtC);
  myESPboy.tft.setCursor(5,10); 
  myESPboy.tft.print(" color is ");          //вывод цвета на дисплее
  myESPboy.tft.setCursor(5,30);
  if (txtC == 0){
    myESPboy.tft.print(" white ");
  }
  if (txtC == 1){
    myESPboy.tft.print(" blue ");
  }
  if (txtC == 2){
    myESPboy.tft.print(" green ");
  }
  if (txtC == 3){
    myESPboy.tft.print(" yellow ");
  }
  if (txtC == 4){
    myESPboy.tft.print(" red ");
  } 
  
  /* === изменение цвета и выход === */
  keypressed = myESPboy.getKeys();
  if (keypressed){      
    myESPboy.tft.fillScreen(TFT_BLACK);
    if (keypressed&PAD_DOWN){
      if (txtC >= 1) { txtC = txtC - 1;}
    }
    
    if (keypressed&PAD_UP){ 
     if (txtC < 4){txtC = txtC + 1;}
    }
    if(keypressed&PAD_ESC){menuH = 1; return; }  
    delay(200);     
  }
  
  myESPboy.tft.setTextSize(1);
}




/*========= цвета дисплея ==========*/
 //color 0 white
 //color 1 blue
 //color 2 green
 //color 3 yellow
 //color 4 red
  
 void TextColor(int color)
 {
  if (color == 0){
    myESPboy.tft.setTextColor(TFT_WHITE);
  }
  if (color == 1){
    myESPboy.tft.setTextColor(TFT_BLUE);
  }
  if (color == 2){
    myESPboy.tft.setTextColor(TFT_GREEN);
  }
  if (color == 3){
    myESPboy.tft.setTextColor(TFT_YELLOW);
  }
  if (color == 4){
    myESPboy.tft.setTextColor(TFT_RED);
  } 
  
 }



  
