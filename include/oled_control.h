#ifndef OLED_CONTROL_H
#define OLED_CONTROL_H

#include <Arduino.h>
#include <heltec.h>
#include <string.h>
#include <stdint.h>
#include "config.h"

using std::string;

class oled_control
{
private:
   /* data */
   void fill_rect();
public:
   oled_control(/* args */);
   ~oled_control();
   void oled_init();
   void startDisplay();
};

#endif  // OLED_CONTROL_H