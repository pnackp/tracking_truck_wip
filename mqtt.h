#pragma once
#include "Wifi_setup.h"
#include <ArduinoJson.h>
#include <PubSubClient.h>

extern PubSubClient client;

void publish_();
void mqtt_setup();