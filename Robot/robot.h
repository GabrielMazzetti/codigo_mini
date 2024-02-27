#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "microStart.h"
#include "digitalSensors.h"
#include "analogSensors.h"
#include "motor.h"
#include "visao.h"
#include "strategy.h"

using namespace std;

#define FRONT_SENSOR_PIN 26
#define FULL_RIGHT_SENSOR_PIN 25
#define FULL_LEFT_SENSOR_PIN 13
#define LEFT_SENSOR_PIN 35
#define RIGHT_SENSOR_PIN 34
#define RIGHT_ANALOGIC_SENSOR_PIN 30
#define LEFT_ANALOGIC_SENSOR_PIN 31

#define RIGHT_MOTOR_PWM_PIN 4
#define RIGHT_MOTOR_IN1_PIN 16
#define RIGHT_MOTOR_IN2_PIN 17
#define RIGHT_MOTOR_SPEED_CONST 1.0
#define RIGHT_MOTOR_CHANNEL 0

#define LEFT_MOTOR_PWM_PIN 21
#define LEFT_MOTOR_IN1_PIN 18
#define LEFT_MOTOR_IN2_PIN 19
#define LEFT_MOTOR_SPEED_CONST 1.0 
#define LEFT_MOTOR_CHANNEL 1

#define MICRO_START_SIGNAL_PIN 2

#define STRATEGY_PIN_A 22
#define STRATEGY_PIN_B 23
#define STRATEGY_PIN_C 14

#define STDBY 5

namespace RobotState
{
    enum States{
        AWAITING_START,
        INITIAL_STRATEGY,
        AUTO_STRATEGY,
        STOPPED
    };
}

class Robot
{
  public:

    string name = "robot";
    int led_pin = 13;
    RobotState::States robot_state;
    uStart ustart;
    DigitalSensors front_sensor;
    DigitalSensors full_left_sensor;
    DigitalSensors full_right_sensor;
    DigitalSensors left_sensor;
    DigitalSensors right_sensor;
    AnalogSensors left_analogic_sensor;
    AnalogSensors right_analogic_sensor;
    MotorControl left_motor;
    MotorControl right_motor;
    Visao visao;
    AutoStrategy auto_strategy;

    void readSensors();
    void update();

    Robot();
    
};

#endif
