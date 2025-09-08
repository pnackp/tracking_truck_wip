#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "Wifi_setup.h"
#include "mqtt.h"
#include "ui.h"

#define temperature 0
#define lat 0
#define lon 0

void setup() {
  LCD_Init();     
  Lvgl_Init();   
  wifi_init();
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  } 
  ui_init();
  mqtt_setup();
}

unsigned long lastPublish = 0;
const unsigned long interval = 2000;

void loop() {
  wifi_status();
  if (WiFi.status() == WL_CONNECTED && millis() - lastPublish >= interval) {
    publish_(temperature,lat,lon);
    lastPublish = millis();
  }
  ui_update();
  Timer_Loop();
  delay(2000);
}
