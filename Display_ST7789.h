#pragma once
#include <Arduino.h>
#include <SPI.h>

// SPI Config
#define SPIFreq                        27000000
#define EXAMPLE_PIN_NUM_MISO           5
#define EXAMPLE_PIN_NUM_MOSI           6
#define EXAMPLE_PIN_NUM_SCLK           7
#define EXAMPLE_PIN_NUM_LCD_CS         14
#define EXAMPLE_PIN_NUM_LCD_DC         15
#define EXAMPLE_PIN_NUM_LCD_RST        21
#define EXAMPLE_PIN_NUM_BK_LIGHT       22
#define Frequency       1000     
#define Resolution      10       



#define HORIZONTAL 1

#if HORIZONTAL
    #define LCD_WIDTH   320   
    #define LCD_HEIGHT  172  
#else
    #define LCD_WIDTH   172
    #define LCD_HEIGHT  320
#endif


#define Offset_X 0
#define Offset_Y 34


void LCD_SetCursor(uint16_t x1, uint16_t y1, uint16_t x2,uint16_t y2);
void LCD_Init(void);
void LCD_SetCursor(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t  Yend);
void LCD_addWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend,uint16_t* color);
void Backlight_Init(void);
void Set_Backlight(uint8_t Light);
