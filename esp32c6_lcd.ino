#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "Wifi_setup.h"
#include "mqtt.h"
#include "ui.h"
#include "SensorBroker.h"

void setup() {
  LCD_Init();     
  Lvgl_Init();  
  ui_init(); 
  wifi_init();
  Serial.println("ui");
  Sensor_Init();
  while (WiFi.status() != WL_CONNECTED) {
    ui_update();          
    Timer_Loop();          
    delay(10);             
  }
  Serial.println("Connected");
  mqtt_setup();
}


unsigned long lastPublish = 0;
const unsigned long interval = 2000;

void loop() {
  ui_update();
  wifi_status();
  if (WiFi.status() == WL_CONNECTED && millis() - lastPublish >= interval) {
    String x = sensor_value();
    publish_(x);
    lastPublish = millis();
  }
  Timer_Loop();
}
