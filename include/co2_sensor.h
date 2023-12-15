#ifndef CO2_SENSOR_H
#define CO2_SENSOR_H

#include <Arduino.h>
#include <stdint.h>
#include "config.h"

class co2_sensor {
  private:
   float CO2Curve[3] = {2.602, ZERO_POINT_VOLTAGE,
                        (REACTION_VOLTGAE / (2.602 - 3))};
   //*Tính toán các dữ liệu thu được từ cảm biến
   float MGRead(int mg_pin);
   int MGGetPercentage(float volts, float* pcurve);

  public:
   co2_sensor(/* args */);
   ~co2_sensor();
   //*Đọc giá trị cảm biến
   int readSensor();
};

#endif  // CO2_SENSOR_H