#include "../include/bluetooth_control.h"

bluetooth_control::bluetooth_control() {}

bluetooth_control::~bluetooth_control() {}

void bluetooth_control::bluetooth_init() {
   SerialBT.begin("Heltec_bluetooth");
   Serial.println("STARTING BLUETOOTH");
}

void bluetooth_control::bluetooth_read() {
   if (Serial.available()) {
      SerialBT.write(Serial.read());
   }
   if (SerialBT.available()) {
      Serial.write(SerialBT.read());
   }
   delay(20);
}