#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>
#include <sstream>
#include "config.h"
#include "oled_control.h"

class controller : public oled_control {
  private:
   /* data */
   struct MOTOR_PINS {
      int en;
      int in_1;
      int in_2;
   };
   MOTOR_PINS* ena = new MOTOR_PINS();
   MOTOR_PINS* enb = new MOTOR_PINS();
   void rolateMotor(MOTOR_PINS* const motorNumber, int motorDirection);
   int speed;

  public:
   controller(/* args */);
   ~controller();
   void controllerInit();
   void moveCar(int state);
   void setSpeed(int speed);
   int getSpeed();
};

#endif  // CONTROLLER.H