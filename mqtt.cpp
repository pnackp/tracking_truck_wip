#include "mqtt.h"

const char* mqtt_server = "192.168.1.34"; 
const uint16_t mqtt_port = 1883;
const char* mqtt_topic = "Sensor/truck"; 

WiFiClient espClient;
PubSubClient client(espClient);

void publish_(){
  client.setServer(mqtt_server, mqtt_port);
  if(!client.connected()){
    client.connect("ESP32_Client");
    delay(300);
  }
  client.publish(mqtt_topic, "buffer");
}