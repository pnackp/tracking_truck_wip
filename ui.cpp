#include "ui.h"

Adafruit_SSD1306 display(OLED_RESET);

void ui_init() {
  Wire.begin(I2C_SDA, I2C_SCL); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  display.display();
}

void ui_update(float temp) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Internet: ");
  display.println(WiFi.status() == WL_CONNECTED ? "OK" : "FAIL!");
  display.print("Server: ");
  display.println(client.connected() ? "OK" : "FAIL!");
  display.print("Temp: ");
  display.print(temp);
  display.println(" oc");
  display.display();
} 