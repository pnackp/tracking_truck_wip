#pragma once
#include "Wifi_setup.h"
#include <ArduinoJson.h>
#include <PubSubClient.h>

extern PubSubClient client;

void publish_(int8_t temperature,float lat,float lon);
void mqtt_setup();