#include "gpsm8n.h"

static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
HardwareSerial gpsSerial(1);

void Gps_Init() {
  gpsSerial.begin(GPSBaud, SERIAL_8N1, 19, 18);
  Serial.begin(115200);
}

void Gps_Update() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
}

double Gps_Read_Lat() {
  if (gps.location.isValid()) {   // แทน isUpdated()
    return gps.location.lat();
  }
  return 0.0;
}

double Gps_Read_Lon() {
  if (gps.location.isValid()) {
    return gps.location.lng();
  }
  return 0.0;
}