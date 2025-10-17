#include "bmpSensor.h"

Adafruit_BMP280 bmp; 

void bmp_Init(){
  Wire.begin(I2C_SDA, I2C_SCL); 
  if (!bmp.begin(0x76)) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
  } else {
    Serial.println("BMP280 sensor was connected successfully!");
  }
}

float bmp_Read(){
  float pressure = bmp.readPressure();
  if (pressure <= 0 || isnan(pressure)) { 
    Serial.println("Failed to read from BMP sensor!");
    return -1;
  }
  return pressure;
}

float bmp_temp(){
  return bmp.readTemperature();
}