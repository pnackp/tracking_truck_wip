#include "ui.h"

lv_obj_t* label;           
lv_obj_t* mqtt_label;       
lv_obj_t* container;

lv_obj_t* create_box(lv_obj_t* parent, const char* text) {
  lv_obj_t* box = lv_obj_create(parent);
  lv_obj_set_size(box, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_style_radius(box, 5, 0);
  lv_obj_set_style_pad_all(box, 10, 0);
  lv_obj_t* lbl = lv_label_create(box);
  lv_label_set_text(lbl, text);
  return lbl;
}

void ui_init() {
  lv_obj_clean(lv_scr_act());
  container = lv_obj_create(lv_scr_act());
  lv_obj_set_size(container, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_style_pad_row(container, 10, 0);
  lv_obj_set_style_pad_all(container, 5, 0);
  lv_obj_set_pos(container, 10, 10);
  lv_obj_set_style_border_width(container, 2, 0);                      
  lv_obj_set_style_border_color(container, lv_color_hex(0x808080), 0); 
  lv_obj_set_style_border_opa(container, LV_OPA_COVER, 0);

  
  label = create_box(container, "WiFi : Initializing...");
  mqtt_label = create_box(container, "MQTT : Initializing...");

  char buff[40];
  sprintf(buff, "ssid : %s pass : %s", ssid, pass);
  lv_obj_t* ssid_pass_label = create_box(container, buff);
}

void ui_update() {
  char buffer[40];
  sprintf(buffer, "Internet : %s", WiFi.status() != WL_CONNECTED ? "Disconnect" : "Connected");
  lv_label_set_text(label, buffer);

  char buffer_mqtt[40];
  sprintf(buffer_mqtt, "MQTT : %s", !client.connected() ? "Disconnect" : "Connected");
  lv_label_set_text(mqtt_label, buffer_mqtt);

  if(WiFi.status() != WL_CONNECTED || !client.connected()){
    lv_obj_set_style_border_color(container, lv_color_hex(0xFF0000), 0); 
  }else{
    lv_obj_set_style_border_color(container, lv_color_hex(0x00FF00), 0); 
  }
}
