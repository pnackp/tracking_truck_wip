#pragma once

#include <ArduinoJson.h>
#include "bmpSensor.h"
#include "max31865_module.h"
#include "gpsm8n.h"
#include "ui.h"

void Sensor_Init();
String sensor_value();