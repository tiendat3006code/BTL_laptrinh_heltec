#include <Arduino.h>
#include "../include/bluetooth_control.h"

bluetooth_control blue;

// put function declarations here:
int myFunction(int, int);

void setup() {
   // put your setup code here, to run once:
   int result = myFunction(2, 3);
   Serial.begin(BAUDRATE);
   blue.init();
   // led.oled_init();
}

void loop() {
   blue.handleData();
}

// put function definitions here:
int myFunction(int x, int y) {
   return x + y;
}