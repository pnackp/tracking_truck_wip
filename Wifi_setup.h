#pragma once
#include <WiFi.h>
#include "mqtt.h"

extern const char * ssid;
extern const char * pass;

void wifi_init();
void wifi_status();