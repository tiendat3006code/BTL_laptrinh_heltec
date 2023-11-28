#ifndef BLUETOOTH_CONTROL_H
#define BLUETOOTH_CONTROL_H

#include <Arduino.h>
#include <BluetoothSerial.h>
#include <stdint.h>
#include <string.h>
#include "config.h"
#include "controller.h"
#include "oled_control.h"

using std::string;

class bluetooth_control : public controller, oled_control {
  private:
   /* data */
   BluetoothSerial SerialBT;
   String remoteName;
   bool isConnected();

  public:
   bluetooth_control(/* args */);
   ~bluetooth_control();
   void bluetooth_init();
   void bluetooth_read();
};

#endif  // BLUETOOTH_CONTROL_H