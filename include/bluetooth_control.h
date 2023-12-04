#ifndef BLUETOOTH_CONTROL_H
#define BLUETOOTH_CONTROL_H

#include <Arduino.h>
#include <BluetoothSerial.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include "co2_sensor.h"
#include "config.h"
#include "controller.h"
#include "oled_control.h"

using std::string, std::vector;

class bluetooth_control {
  private:
   /* data */
   BluetoothSerial SerialBT;
   String remoteName;
   bool isConnected();
   void bluetooth_read();
   controller* con = new controller();
   oled_control* led = new oled_control();
   co2_sensor* sensor = new co2_sensor();

  public:
   bluetooth_control(/* args */);
   ~bluetooth_control();
   void init();
   void handleData();
};

#endif  // BLUETOOTH_CONTROL_H