#ifndef OLED_CONTROL_H
#define OLED_CONTROL_H

#include <Arduino.h>
#include <heltec.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include "config.h"

using std::string;

class oled_control {
  private:
   /* data */
   //*Xóa các thông tin đang hiển thị trên màn hình
   void fill_rect();
   int powerPercent;

  public:
   oled_control(/* args */);
   ~oled_control();
   //*Cài đặt các thông số ban đầu cho màn hình led
   void oled_init();
   //*Hiển thị các thông số đầu tiên được cài đặt cho xe
   void startDisplay();
   //*Test màn hình
   //! Hàm này chỉ dùng để test màn hình
   void test_display();
   //*Hiển thị trạng thái của xe
   //! Hàm này không được cài đặt
   void display_state(int state);
   //*Hiển thị giá trị xung PWM
   void display_power(int power);
   //*Hiển thị giá trị đo được từ cảm biến
   void display_sensor(int value);
};

#endif  // OLED_CONTROL_H