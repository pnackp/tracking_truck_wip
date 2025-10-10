#include "bmpSensor.h"

BMP180 bmp;

void bmp_Init(){
  Wire.begin(I2C_SDA, I2C_SCL); 
  bmp.begin();
}

float bmp_Read(){
  return bmp.readPressure();
}