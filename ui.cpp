#include "ui.h"

Adafruit_SSD1306 display(OLED_RESET);

void ui_init() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  display.display();
}

void ui_update() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Internet: ");
  display.println(WiFi.status() == WL_CONNECTED ? "Connected" : "Disconnected");
  display.print("Server: ");
  display.println(client.connected() ? "Connected" : "Disconnected");
  display.print("wifi: ");
  display.print(ssid);
  display.println(pass);
  display.display();
}