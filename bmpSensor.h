#pragma once
#include <Wire.h>
#include <BMP180.h>

#define I2C_SDA 20     
#define I2C_SCL 23

void bmp_Init();
float bmp_Read();