#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <Arduino.h>
#include <iostream>
#include <sstream>
#include <vector>
#include "config.h"

using std::vector;

class controller
{
private:
    /* data */
    struct MOTOR_PINS{
    int en;
    int in_1;
    int in_2;
    };
    MOTOR_PINS *ena = new MOTOR_PINS();
    MOTOR_PINS *enb = new MOTOR_PINS();
    void rolateMotor(int motorNumber, int motorDirection);
    
public:
    controller(/* args */);
    ~controller();
    void controllerInit();
    void moveCar(int value);
};

#endif //CONTROLLER.H