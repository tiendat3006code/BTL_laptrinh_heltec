#include <Arduino.h>
#include "../include/bluetooth_control.h"
#include "../include/oled_control.h"
#include "../include/controller.h"
#include "../include/co2_sensor.h"

bluetooth_control blue;
oled_control led;
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
   // led.test_display();
}

// put function definitions here:
int myFunction(int x, int y) {
   return x + y;
}