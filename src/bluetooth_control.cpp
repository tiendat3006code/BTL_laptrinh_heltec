#include "../include/bluetooth_control.h"

bluetooth_control::bluetooth_control() {}

bluetooth_control::~bluetooth_control() {
   SerialBT.end();
   con->~controller();
   led->~oled_control();
   sensor->~co2_sensor();
   delete con, led, sensor;
   con = nullptr;
   led = nullptr;
   sensor = nullptr;
}

void bluetooth_control::init() {
   SerialBT.begin("Heltec_bluetooth");
   SerialBT.connect();
   Serial.println("STARTING BLUETOOTH");
   con->setSpeed(250);
   con->controllerInit();
   led->oled_init();
   led->startDisplay();
   delay(1000);
}

void bluetooth_control::bluetooth_read() {
   if (!isConnected())
      return;
   if (!SerialBT.available())
      return;
   char l = SerialBT.read();
   Serial.print("Data: ");
   // SerialBT.println(l);
   switch (l) {
      case 'f':
         con->moveCar(UP);
         break;
      case 'b':
         con->moveCar(DOWN);
         break;
      case 'r':
         con->moveCar(RIGHT);
         break;
      case 'l':
         con->moveCar(LEFT);
         break;
      case 's':
         con->moveCar(STOP);
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
   con->PWMwrite();
   led->display_power(con->getSpeed());
   led->display_sensor(sensor->readSensor());
   Heltec.display->display();
   // SerialBT.print(sensor->readSensor());
}