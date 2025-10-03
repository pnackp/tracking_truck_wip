#include "gpsm8n.h"

static const int RXPin = 16;
static const int TXPin = 15;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);

void Gps_Init() {
  gpsSerial.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);
}

void Gps_Update() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
}

double Gps_Read_Lat() {
  if (gps.location.isUpdated()) {
    return gps.location.lat();
  }
  return 0.0;
}

double Gps_Read_Lon() {
  if (gps.location.isUpdated()) {
    return gps.location.lng(); // TinyGPS++ ใช้ lng() ไม่ใช่ lon()
  }
  return 0.0;
}