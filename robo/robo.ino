#include "robot.h"
#include "Arduino.h"




void setup(){

   Serial.begin(115200);
   
   pinMode(FRONT_SENSOR_PIN, INPUT);
   pinMode(RIGHT_SENSOR_PIN, INPUT);
   pinMode(LEFT_SENSOR_PIN, INPUT);
   pinMode(LEFT_ANALOGIC_SENSOR_PIN, INPUT);
   pinMode(RIGHT_ANALOGIC_SENSOR_PIN, INPUT);
   pinMode(RIGHT_MOTOR_PWM_PIN, OUTPUT);
   pinMode(RIGHT_MOTOR_IN1_PIN, OUTPUT);
   pinMode(RIGHT_MOTOR_IN2_PIN, OUTPUT);
   pinMode(LEFT_MOTOR_PWM_PIN, OUTPUT);
   pinMode(LEFT_MOTOR_IN1_PIN, OUTPUT);
   pinMode(LEFT_MOTOR_IN2_PIN, OUTPUT);
   pinMode(MICRO_START_SIGNAL_PIN, INPUT);


}

void loop(){
    
    delay(1000);

    Robot robo;
    robo.update();
}