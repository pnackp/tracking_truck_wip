#include "Wifi_setup.h"

const char * ssid = "NACK 2.4p";
const char * pass = "0828231976";

void wifi_init(){
  WiFi.disconnect();
  WiFi.begin(ssid,pass);
}

void wifi_status(){
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
    delay(500);
  }
}
