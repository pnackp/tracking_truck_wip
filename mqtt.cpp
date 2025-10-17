#include "mqtt.h"

const char* mqtt_server = "0e32e8159fa94935aee6fe0a5500e61c.s1.eu.hivemq.cloud";
const uint16_t mqtt_port = 8883;
const char* mqtt_topic = "Sensor/truck";

const char* mqtt_user = "Admin"; 
const char* mqtt_pass = "0956125246As"; 

WiFiClientSecure espClient;
PubSubClient client(espClient);

void mqtt_setup() {
  Serial.begin(115200);
  espClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);
}

void publish_(String &payload) {
  if (!client.connected()) {
    if (client.connect("ESP32_Client", mqtt_user, mqtt_pass)) {
      Serial.println("MQTT connected!");
    } else {
      Serial.print("MQTT connect failed, rc=");
      Serial.println(client.state());
      return; 
    }
  }
  client.publish(mqtt_topic, payload.c_str());
}