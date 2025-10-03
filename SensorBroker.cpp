#include "SensorBroker.h"

void Sensor_Init(){
  bmp_Init();
  Max_Init();
  Gps_Init();
}

String sensor_value() {
  Gps_Update();
  float lat = Gps_Read_Lat();
  float lon = Gps_Read_Lon();

  StaticJsonDocument<100> doc;
  doc["latitude"] = lat;
  doc["longitude"] = lon;

  String result;
  serializeJson(doc, result);

  return result;  
}