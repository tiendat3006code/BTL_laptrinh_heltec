#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>
#include <sstream>
#include "config.h"
#include "oled_control.h"

class controller {
  private:
   /* data */
   struct MOTOR_PINS {
      int en;
      int in_1;
      int in_2;
   };
   MOTOR_PINS* ena = new MOTOR_PINS();
   MOTOR_PINS* enb = new MOTOR_PINS();
   //*Điều khiển động cơ tiến hay lùi
   void rolateMotor(MOTOR_PINS* const motorNumber, int motorDirection);
   int speed;

  public:
   controller(/* args */);
   ~controller();
   //*Cài đặt các thông số cho mạch L298
   void controllerInit();
   //*Điều khiển hướng di chuyển của xe
   void moveCar(int state);
   //*Cài đặt giá trị xung PWM
   void setSpeed(int speed);
   //*Lấy giá trị xung PWM đang được cài đặt
   int getSpeed();
   //*Băm xung PWM
   void PWMwrite();
};

#endif  // CONTROLLER.H