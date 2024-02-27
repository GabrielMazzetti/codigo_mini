#include "Motor.h"
#include <Arduino.h>
#include <iostream>
using namespace std;


MotorConfig::MotorConfig(int pwmPin, int pinA, int pinB, float speedConst){

   this->pwmPin = pwmPin;
   this->pinA = pinA;
   this->pinB = pinB;
   this->speedConst = speedConst;

}

MotorControl::MotorControl(int pwmPin, int pinA, int pinB, float speedConst): config(pwmPin, pinA, pinB, speedConst){
  
}

void MotorControl::setPower(int power){

   this->power = power;
   float pTotal = power * config.speedConst;
   int pwm = this->maxPower/100 * 255 * (abs(pTotal)/100);

   if(pTotal < 0 && pTotal >= -100)
     digitalWrite(this->config.pinA, false);

   else if(pTotal >= 0 && pTotal <= 100)
     digitalWrite(this->config.pinB, true);

   else 
      cout << "Valor inválido de potência!" << endl;   
}