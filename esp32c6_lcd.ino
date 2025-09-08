#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "Wifi_setup.h"
#include "mqtt.h"

void setup() {
  LCD_Init();     
  Lvgl_Init();   
  wifi_init();
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  } 
}

unsigned long lastPublish = 0;
const unsigned long interval = 2000;

void loop() {
  wifi_status();
  if (WiFi.status() == WL_CONNECTED && millis() - lastPublish >= interval) {
    publish_();
    lastPublish = millis();
  }
  Timer_Loop();
  delay(2000);
}
