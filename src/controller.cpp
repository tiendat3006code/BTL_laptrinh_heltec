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

    ledcSetup(PWMCHANNEL, PWMFREQ, PWMRES);
    ledcAttachPin(ena->en, PWMCHANNEL);
    ledcAttachPin(enb->en, PWMCHANNEL);

    ledcWrite(PWMCHANNEL, speed);

    moveCar(STOP);

    Serial.println("INIT CONTROLLER SUCCESS");
}

void controller::moveCar(int state){
    switch (state)
    {
    case UP:
        {
            rolateMotor(ena, FORWARD);
            rolateMotor(enb, FORWARD);
            Serial.println("CAR MOVE UP");
            break;
        }
    case DOWN:
    {
        rolateMotor(ena, BACKWARD);
        rolateMotor(enb, BACKWARD);
        Serial.println("CAR MOVE DOWN");
        break;
    }
    
    case STOP:
    {
        rolateMotor(ena, STOP);
        rolateMotor(enb, STOP);
        Serial.println("CAR STOP");
        break;
    }

    case RIGHT:
    {
        rolateMotor(ena, BACKWARD);
        rolateMotor(enb, FORWARD);
        Serial.println("CAR TURN RIGHT");
        break;
    }

    case LEFT:
    {
        rolateMotor(ena, FORWARD);
        rolateMotor(enb, BACKWARD);
        Serial.println("CAR TURN LEFT");
        break;
    }
    default:
        break;
    }
}

void controller::rolateMotor(MOTOR_PINS *const motorNumber, int motorDirection){
    switch (motorDirection)
    {
    case FORWARD:
        {
        digitalWrite(motorNumber->in_1, HIGH);
        digitalWrite(motorNumber->in_2, LOW);
        break;
        }
    case BACKWARD:
    {
        digitalWrite(motorNumber->in_1, LOW);
        digitalWrite(motorNumber->in_2, HIGH);
        break;
    }

    case STOP:
    {
        digitalWrite(motorNumber->in_1, LOW);
        digitalWrite(motorNumber->in_2, LOW);
        break;
    }
    default:
        break;
    }
}

void controller::setSpeed(int speed){
    this->speed = speed;
}

int controller::getSpeed(){
    ledcWrite(PWMCHANNEL, speed);
    return speed;
}