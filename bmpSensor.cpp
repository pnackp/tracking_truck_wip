#include "bmpSensor.h"

BMP180 bmp;

void bmp_Init(){
  bmp.begin();
}

float bmp_Read(){
  return bmp.readPressure();
}