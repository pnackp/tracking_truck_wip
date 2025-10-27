#include "SensorBroker.h"

void Sensor_Init(){
  ui_init();
  bmp_Init();
  Max_Init();
  Gps_Init();
}

String sensor_value() {
  Gps_Update();
  float lat = Gps_Read_Lat();
  float lon = Gps_Read_Lon();
  float temp = Max_Read();       
  float pressure = bmp_Read(); 
  float temp_o = bmp_temp();
  StaticJsonDocument<200> doc; 
  doc["latitude"] = lat;
  doc["longitude"] = lon;
  doc["temperature"] = temp - 1.2;    
  doc["pressure"] = pressure / 100;    
  doc["temp-out"] = temp_o;
  String result;
  serializeJson(doc, result);
  ui_update(temp - 1.2);
  return result;  
}