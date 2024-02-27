#include "robot.h"
#include <iostream>
#include <Arduino.h>
using namespace std;

Robot::Robot():front_sensor(FRONT_SENSOR_PIN), full_left_sensor(FULL_LEFT_SENSOR_PIN), full_right_sensor(FULL_RIGHT_SENSOR_PIN), left_sensor(LEFT_SENSOR_PIN), right_sensor(RIGHT_SENSOR_PIN),left_analogic_sensor(LEFT_ANALOGIC_SENSOR_PIN),right_analogic_sensor(RIGHT_ANALOGIC_SENSOR_PIN) ,left_motor(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_IN1_PIN, LEFT_MOTOR_IN2_PIN, LEFT_MOTOR_SPEED_CONST), right_motor(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_IN1_PIN, RIGHT_MOTOR_IN2_PIN, RIGHT_MOTOR_SPEED_CONST), ustart(MICRO_START_SIGNAL_PIN), visao()
{
  this->robot_state = RobotState::AWAITING_START;

}

void Robot::readSensors() {

  
  Serial.println("esq: ");
  this->left_sensor.reading(); 
  Serial.println(" \t dir: ");
  this->right_sensor.reading(); 
  
  this->front_sensor.reading();  
  this->full_left_sensor.reading(); 
  this->full_right_sensor.reading(); 
  
  

}
void Robot::update() {
  this->ustart.update();
  this->readSensors();
  this->visao.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, this->right_sensor);

  if (ustart.state == uStartState::START){  
    if (this->robot_state == RobotState::AUTO_STRATEGY){
      this->auto_strategy.updateMotors(this->visao, this->left_motor, this->right_motor);      
    }    
    else{
    this->robot_state = RobotState::STOPPED;
    left_motor.setPower(0);
    right_motor.setPower(0);    
  }      
}

}