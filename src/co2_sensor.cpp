#include "../include/co2_sensor.h"

co2_sensor::co2_sensor() {
   pinMode(MG_PIN, INPUT);
}

co2_sensor::~co2_sensor() {}

int co2_sensor::readSensor() {
   int percentage;
   float volts;

   volts = MGRead(MG_PIN);
   Serial.print("SEN0159:");
   Serial.print(volts);
   Serial.print("V           ");

   percentage = MGGetPercentage(volts, CO2Curve);
   Serial.print("CO2:");
   if (percentage == -1) {
      Serial.print("<400");
   } else {
      Serial.print(percentage);
   }

   Serial.println("ppm");
   return percentage;
}

float co2_sensor::MGRead(int mg_pin) {
   int i;
   float v = 0;

   for (i = 0; i < READ_SAMPLE_TIMES; i++) {
      v += analogRead(mg_pin);
      delay(READ_SAMPLE_INTERVAL);
   }
   v = (v / READ_SAMPLE_TIMES) * 5 / 1024;
   return v;
}

int co2_sensor::MGGetPercentage(float volts, float* pcurve) {
   if ((volts / DC_GAIN) >= ZERO_POINT_VOLTAGE) {
      return -1;
   } else {
      return pow(10, ((volts / DC_GAIN) - pcurve[1]) / pcurve[2] + pcurve[0]);
   }
}