#include "mqtt.h"

const char* mqtt_server = "192.168.1.34";
const uint16_t mqtt_port = 1883;
const char* mqtt_topic = "Sensor/truck";

WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_setup() {
  client.setServer(mqtt_server, mqtt_port);
}

void publish_(int8_t temperature, float lat, float lon) {
  if (!client.connected()) {
    client.connect("ESP32_Client");
    delay(300);
  }
  StaticJsonDocument<100> doc;
  doc["temperature"] = temperature;
  doc["latitude"] = lat;
  doc["longitude"] = lon;
  String jsonStr;
  char buffer[100];
  serializeJson(doc, buffer);
  client.publish(mqtt_topic, buffer);
}