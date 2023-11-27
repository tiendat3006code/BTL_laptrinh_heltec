#include <Arduino.h>
#include "../include/controller.h"
#include "../include/oled_control.h"
#include "../include/bluetooth_control.h"

controller con;
oled_control led;
bluetooth_control blue;

// put function declarations here:
int myFunction(int, int);

void setup() {
   // put your setup code here, to run once:
   int result = myFunction(2, 3);
   Serial.begin(BAUDRATE);
   // con.setSpeed(250);
   // con.controllerInit();
   led.oled_init();
   blue.bluetooth_init();
}

void loop() {
   // put your main code here, to run repeatedly:
   // if (Serial.available() > 0) {
   //    switch (Serial.read()) {
   //       case 'u': {
   //          con.setSpeed(255);
   //          con.moveCar(UP);
   //          break;
   //       }
   //       case 's': {
   //          con.moveCar(STOP);
   //          break;
   //       }
   //       case 'f': {
   //          con.setSpeed(100);
   //          con.moveCar(UP);
   //          break;
   //       }
   //       default:
   //          break;
   //    }
   // }
   // con.getSpeed();
   // led.oled_test();
   blue.bluetooth_read();
}

// put function definitions here:
int myFunction(int x, int y) {
   return x + y;
}