#include "Wifi_setup.h"
#include "mqtt.h"
#include "SensorBroker.h"

void setup() {
  wifi_init();
  Sensor_Init();
  while (WiFi.status() != WL_CONNECTED) {        
    delay(10);             
  }
  mqtt_setup();
}

unsigned long lastPublish = 0;
const unsigned long interval = 2000;

void loop() {
  wifi_status();
  client.loop();
  if (WiFi.status() == WL_CONNECTED && millis() - lastPublish >= interval) {
    String x = sensor_value();
    publish_(x);
    lastPublish = millis();
  }
}
