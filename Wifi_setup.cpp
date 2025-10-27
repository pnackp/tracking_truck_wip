#include "Wifi_setup.h"

WiFiManager wm;

void wifi_init(){
  bool connected = wm.autoConnect("Sensor_AP", "12345678"); 
  if (!connected) {
    ESP.restart(); 
  }
}

void wifi_status(){
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
    delay(500);
  }
}
