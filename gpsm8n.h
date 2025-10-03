#pragma once 

#include <TinyGPS++.h>
#include <HardwareSerial.h>


void Gps_Init();
void Gps_Update();
double Gps_Read_Lat();
double Gps_Read_Lon();