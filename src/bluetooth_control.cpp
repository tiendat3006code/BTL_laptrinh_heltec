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
   vector<int> data;
   while (SerialBT.available()) {
      int l = SerialBT.read();
      SerialBT.flush();
      if (l >= 0)
         data.push_back(l);
      else
         SerialBT.flush();
   }
   // Serial.print("Data: ");
   // SerialBT.println(l);
   if (static_cast<uint8_t>(data.at(0)) == POWER)
      con->setSpeed(data.at(1));
   else if (static_cast<uint8_t>(data.at(0)) == CONTROL) {
      switch (static_cast<uint8_t>(data.at(1))) {
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