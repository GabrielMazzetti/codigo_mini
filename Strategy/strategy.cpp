#include "strategy.h"
#include "visao.h"
#include <iostream>

using namespace std;


void AutoStrategy::updateMotors(Visao &visao, MotorControl &left_motor, MotorControl &right_motor){

    if(visao.esquerda == 1){ //se a vari�vel esquerda = 1, significa que o sensor anal�gico da esquerda identificou a cor branca

        left_motor.setPower(90);
        right_motor.setpower(10);
    }
    
    else if(visao.direita == 2){ //se a vari�vel direita = 2, significa que o sensor anal�gico da direita identificou a cor branca

        left_motor.setPower(10);
        right_motor.setPower(90);
    }

    else if(visao.ambos == 3){ //se a vari�vel ambos = 3, significa que ambos os sensores anal�gicos identificaram a cor branca

        left_motor.setPower(-100);
        right_motor.setpower(-100);
    }
    else if(visao.enemy_position == EnemyPosition::RIGHT){
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