#ifndef BLUETOOTH_CONTROL_H
#define BLUETOOTH_CONTROL_H

#include <Arduino.h>
#include <BluetoothSerial.h>
#include <stdint.h>
#include <string.h>
#include "config.h"
#include "controller.h"
#include "oled_control.h"
#include "co2_sensor.h"

using std::string;

class bluetooth_control : public controller, co2_sensor {
  private:
   /* data */
   BluetoothSerial SerialBT;
   String remoteName;
   bool isConnected();
   void bluetooth_read();

  public:
   bluetooth_control(/* args */);
   ~bluetooth_control();
   void init();
   void handleData();
};

#endif  // BLUETOOTH_CONTROL_H