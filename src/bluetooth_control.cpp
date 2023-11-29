#include "../include/bluetooth_control.h"

bluetooth_control::bluetooth_control() {}

bluetooth_control::~bluetooth_control() {
   SerialBT.end();
}

void bluetooth_control::init() {
   SerialBT.begin("Heltec_bluetooth");
   Serial.println("STARTING BLUETOOTH");
   controller::setSpeed(250);
   controller::controllerInit();
   oled_control::oled_init();
   oled_control::startDisplay();
   delay(1000);
}

void bluetooth_control::bluetooth_read() {
   if (!isConnected())
      return;
   if (!SerialBT.available())
      return;
   char l = SerialBT.read();
   Serial.print("Data: ");
   SerialBT.println(l);
   switch (l) {
      case 'f':
         controller::moveCar(UP);
         break;
      case 'b':
         controller::moveCar(DOWN);
         break;
      case 'r':
         controller::moveCar(RIGHT);
         break;
      case 'l':
         controller::moveCar(LEFT);
         break;
      case 's':
         controller::moveCar(STOP);
         break;

      default:
         break;
   }
   delay(20);
}

bool bluetooth_control::isConnected() {
   if (SerialBT.hasClient()) {
      //? don't know true or not
      // remoteName = SerialBT.get
      // Serial.println(remoteName);
      return true;
   } else {
      return false;
   }
}

void bluetooth_control::handleData() {
   bluetooth_read();
   oled_control::display_sensor(co2_sensor::readSensor());
   controller::getSpeed();
   Heltec.display->display();
}