#pragma once
#include <WiFiManager.h>
#include "mqtt.h"

extern WiFiManager wm;

void wifi_init();
void wifi_status();