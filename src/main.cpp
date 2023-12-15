#include <Arduino.h>
#include "../include/bluetooth_control.h"
#include "../include/co2_sensor.h"
#include "../include/controller.h"
#include "../include/oled_control.h"

bluetooth_control blue;
// put function declarations here:

void setup() {
   // put your setup code here, to run once:
   Serial.begin(BAUDRATE);
   blue.init();
   // led.oled_init();
}

void loop() {
   blue.handleData();
   // led.test_display();
}

// put function definitions here:
