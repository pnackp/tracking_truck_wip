#include "bmpSensor.h"

Adafruit_BMP280 bmp; 

void bmp_Init(){
  Wire.begin(I2C_SDA, I2C_SCL); 
  if (!bmp.begin(0x76)) {
    Serial.println("can not connect to Address 0x76");
  }
}

float bmp_Read(){
  float pressure = bmp.readPressure();
  if (pressure <= 0 || isnan(pressure)) { 
    return -1;
  }
  return pressure;
}

float bmp_temp(){
  return bmp.readTemperature();
}