#ifndef OLED_CONTROL_H
#define OLED_CONTROL_H

#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>
#include <U8x8lib.h>
#include <Wire.h>
#include <heltec.h>
#include <stdbool.h>
#include <stdint.h>
#include "config.h"

#define PAGE_BUFFER

class oled_control {
  private:
#ifdef PAGE_BUFFER
   U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2;
#endif

#ifdef FULL_BUFFER
   U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2;
#endif

#ifdef U8X8
   U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8;
#endif
  public:
   oled_control(/* args */);
   ~oled_control();
   void oled_init();
   void oled_test();
};

#endif  // OLED_CONTROL_H