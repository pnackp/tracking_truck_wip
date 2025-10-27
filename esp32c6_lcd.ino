#include "Wifi_setup.h"
#include "mqtt.h"
#include "SensorBroker.h"

void setup() {
  Serial.begin(115200);
  ui_init();
  ui_update(0);
  wifi_init();
  Sensor_Init();
  while (WiFi.status() != WL_CONNECTED) {        
    delay(10);             
  }
  mqtt_setup();
}

uint32_t  lastPublish = 0;
const uint16_t interval = 2000;

void loop() {
  wifi_status();
  client.loop();
  if (WiFi.status() == WL_CONNECTED && millis() - lastPublish >= interval) {
    String x = sensor_value();
    publish_(x);
    lastPublish = millis();
  }
}
