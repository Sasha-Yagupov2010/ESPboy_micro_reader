void build() {                      // Билд страницы
  GP.BUILD_BEGIN(400);              // Ширина колонок
  GP.THEME(GP_DARK);                // Темная тема
  GP.PAGE_TITLE("Wi-Fi Reader");    // Обзываем титл
  GP.FORM_BEGIN("/cfg");            // Начало формы
  GP.GRID_RESPONSIVE(600);          // Отключение респонза при узком экране
  M_BLOCK(                          // Общий блок-колонка для WiFi
    GP.SUBMIT("SUBMIT SETTINGS");   // Кнопка отправки формы
    M_BLOCK_TAB(                    // Конфиг для AP режима -> текстбоксы (логин + пароль)
      "AP-Mode",                    // Имя + тип DIV
      GP.TEXT("apSsid", "Login", ssid , "", 20); GP.BREAK();
      GP.TEXT("apPass", "Password", password , "", 20); GP.BREAK();
    );
    GP.FORM_END();                  // <- Конец формы (костыль)
    M_BLOCK_TAB(                    // Блок с OTA-апдейтом
      "ESP UPDATE",                 // Имя + тип DIV
      GP.OTA_FIRMWARE();            // Кнопка с OTA начинкой
    );
    M_BLOCK_TAB(                    // Блок с файловым менеджером
      "FILE MANAGER",               // Имя + тип DIV
      GP.FILE_UPLOAD("file_upl");   // Кнопка для загрузки файла
      GP.FILE_MANAGER(&LittleFS);   // Файловый менеджер
    );
  );
  GP.BUILD_END();                   // Конец билда страницы
}


void action(GyverPortal& p) {       // Подсос значений со страницы
  if (p.form("/cfg")) {             // Если есть сабмит формы - копируем все в переменные
    p.copyStr("apSsid", ssid);
    p.copyStr("apPass", password);
  }
  }


void enterToWifiMenu(void) {  
  myESPboy.tft.setTextColor(TFT_YELLOW);
  myESPboy.tft.setCursor(5,5);
  myESPboy.tft.print("Wi-Wi Uploader V1.0");
  myESPboy.tft.setTextColor(TFT_WHITE);
  myESPboy.tft.setCursor(5,20);
  myESPboy.tft.print(ssid);
  myESPboy.tft.setCursor(5,50);
  myESPboy.tft.print(password);
  myESPboy.tft.setTextColor(TFT_YELLOW);
  delay(100);

  WiFi.mode(WIFI_AP);                               // Если STA режим пропущен врубаем AP
  WiFi.softAP(ssid, password);                      // Создаем сеть
  ui.attachBuild(build);                            // Подключаем билд веб морды
  ui.attach(action);                                // Подключаем обработчик действий
  ui.start();                                       // Стартуем!
  ui.enableOTA();  
                                                     // Включаем ОТА для прошивки по воздуху
  while (1) {       
  delay(100);                                        // Бесконечный цикл
  keypressed = myESPboy.getKeys();   
   if (keypressed){                                             
      WiFi.softAPdisconnect();                      // Отключаем точку доступа
      WiFi.mode(WIFI_OFF);                          // Вырубаем wifi
      menuH = 1;
      return;                                      // Валим из функции
    }    
    ui.tick();                                      // Тикер портала
    yield();                                        // Внутренний поллинг ESP
  }
}
