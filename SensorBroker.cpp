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

  StaticJsonDocument<200> doc; 
  doc["latitude"] = lat;
  doc["longitude"] = lon;
  doc["temperature"] = temp;    
  doc["pressure"] = pressure;    

  String result;
  serializeJson(doc, result);

  return result;  
}