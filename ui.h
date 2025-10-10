#pragma once
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "bmpSensor.h"
#include "Wifi_setup.h"
#include "mqtt.h"
#define OLED_RESET -1

void ui_init();
void ui_update();