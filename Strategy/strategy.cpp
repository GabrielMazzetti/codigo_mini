#include "Strategy.h"
#include "Visao.h"
#include <iostream>

using namespace std;


void AutoStrategy::updateMotors(Visao &visao, MotorControl &left_motor, MotorControl &right_motor){

    if(visao.enemy_position == EnemyPosition::RIGHT){
        left_motor.setPower(90);
        right_motor.setPower(10);
    }

    else if(visao.enemy_position == EnemyPosition::LEFT){
        left_motor.setPower(10);
        right_motor.setPower(90);  
    }

    else if(visao.enemy_position == EnemyPosition::FRONT){
        left_motor.setPower(100);
        right_motor.setPower(100);
    }

    else if(visao.enemy_position == EnemyPosition::FULL_RIGHT){
        left_motor.setPower(95);
        right_motor.setPower(5);
    }

    else if(visao.enemy_position == EnemyPosition::FULL_LEFT){
        left_motor.setPower(5);
        right_motor.setPower(95);
    }

};