#ifndef BLUETOOTH_CONTROL_H
#define BLUETOOTH_CONTROL_H

#include <Arduino.h>
#include <BluetoothSerial.h>
#include <stdint.h>
#include "config.h"

class bluetooth_control {
  private:
   /* data */
   BluetoothSerial SerialBT;

  public:
   bluetooth_control(/* args */);
   ~bluetooth_control();
   void bluetooth_init();
   void bluetooth_read();
};

#endif  // BLUETOOTH_CONTROL_H