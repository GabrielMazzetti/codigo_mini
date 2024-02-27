#ifndef Motor_H
#define Motor_H

#include <Arduino.h>


struct MotorConfig{

   float speedConst;
   int pwmPin;
   int pinA;
   int pinB;
   MotorConfig(int pwmPin, int pinA, int pinB, float speedConst);

};


class MotorControl{

   public:

   float maxPower= 100;
   int power;
   MotorConfig config;
   void setPower(int power);
   MotorControl(int pwmPin, int pinA, int pinB, float speedConst);

};

#endif 