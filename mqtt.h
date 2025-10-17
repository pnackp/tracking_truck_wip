#pragma once
#include "Wifi_setup.h"
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
extern PubSubClient client;

void publish_(String &payload);
void mqtt_setup();