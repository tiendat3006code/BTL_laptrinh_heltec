#include <Arduino.h>
#include "../include/controller.h"

controller con;
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(BAUDRATE);
  con.controllerInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  con.moveCar(UP);
  //EnA tien
  // analogWrite(IN_1, 0);
  // analogWrite(IN_2, 250);
  // //EnB lui
  // analogWrite(IN_3, 250);
  // analogWrite(IN_4, 0);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}