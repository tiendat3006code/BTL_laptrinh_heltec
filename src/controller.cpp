#include "../include/controller.h"

controller::controller(){
    ena->en = ENA;
    ena->in_1 = IN_1;
    ena->in_2 = IN_2;

    enb->en = ENB;
    enb->in_1 = IN_3;
    enb->in_2 = IN_4;
}

controller::~controller(){
    delete ena, enb;
    ena = nullptr;
    enb = nullptr;
}

void controller::controllerInit(){
    pinMode(ena->en, OUTPUT);
    pinMode(ena->in_1, OUTPUT);
    pinMode(ena->in_2, OUTPUT);

    pinMode(enb->en, OUTPUT);
    pinMode(enb->in_1, OUTPUT);
    pinMode(enb->in_2, OUTPUT);

    // ledcAttachPin(ena->en, PWMSPEED);
    // ledcAttachPin(enb->en, PWMSPEED);

    // ledcSetup(PWMSPEED, PWMFREQ, PWMRES);

    analogWrite(ena->en, 255);
    analogWrite(enb->en, 255);

    moveCar(UP);

    Serial.println("INIT CONTROLLER SUCCESS");
}

void controller::moveCar(int value){
    // switch (value)
    // {
    // case UP:
    //     {
            rolateMotor(RIGHT_MOTOR, FORWARD);
            rolateMotor(LEFT_MOTOR, FORWARD);
    //         Serial.println("CAR MOVE UP");
    //         break;
    //     }
        
    
    // default:
    //     break;
    // }
}

void controller::rolateMotor(int motorNumber, int motorDirection){
    // switch (motorDirection)
    // {
    // case FORWARD:
    //     {
        digitalWrite(ena->in_1, HIGH);
        digitalWrite(ena->in_2, LOW);

        digitalWrite(enb->in_1, HIGH);
        digitalWrite(enb->in_2, LOW);
    //     break;
    //     }
    // case BACKWARD:
    // {
    //     digitalWrite(ena->in_1, LOW);
    //     digitalWrite(ena->in_2, HIGH);
    //     break;
    // }

    // default:
    //     break;
    // }
}