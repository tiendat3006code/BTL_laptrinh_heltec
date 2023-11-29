#ifndef OLED_CONTROL_H
#define OLED_CONTROL_H

#include <Arduino.h>
#include <heltec.h>
#include <string.h>
#include <stdint.h>
#include "config.h"
#include <sstream>

using std::string;

class oled_control
{
private:
   /* data */
   void fill_rect();
   int powerPercent;
public:
   oled_control(/* args */);
   ~oled_control();
   void oled_init();
   void startDisplay();
   void test_display();
   void display_state(int state);
   void display_power(int power);
   void display_sensor(int value);
};

#endif  // OLED_CONTROL_H