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
   blue.bluetooth_init();
}

void loop() {
   blue.bluetooth_read();
}

// put function definitions here:
int myFunction(int x, int y) {
   return x + y;
}