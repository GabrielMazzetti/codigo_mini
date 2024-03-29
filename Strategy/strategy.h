#ifndef STRATEGY_H
#define STRATEGY_H

#include <Arduino.h>
#include "visao.h"
#include "motor.h"

class Move
{
  int left_motor_power;
  int right_motor_power;
  int time_ms;
  int start_time_ms;
  bool started;
  bool finished;
  bool update(MotorControl &left_motor, MotorControl &right_motor);
  Move(int left_motor_power, int right_motor_power, int time_ms);

};

class AutoStrategy 
{
public: 
  int left_motor_power;
  int right_motor_power;
  void updateMotors (Visao &visao, MotorControl &left_motor, MotorControl &right_motor);
};






#endif