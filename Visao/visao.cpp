#include <Arduino.h>
#include "visao.h"
#include "digitalSensors.h"
#include "analogSensors.h"
#include <iostream>
using namespace std;

void Visao::updateEnemyPosition(DigitalSensors &front_sensor, DigitalSensors &full_left_sensor, 
DigitalSensors &left_sensor, DigitalSensors &right_sensor, DigitalSensors &full_right_sensor, AnalogSensors &left_analog_sensor, AnalogSensors &right_analog_sensor){

   if(left_analog_sensor.identificaBranco != 0 && right_analog_sensor == 0){

      this->esquerda = 1; //primeiro caso

    return;
   }

   else if(right_analog_sensor != 0 && left_analog_sensor == 0){

      this->direita = 2; //segundo caso

      return;
   }

   else if(left_analog_sensor != 0 && right_analog_sensor != 0){

      this->ambos = 3; //terceiro caso

      return;
      
   }
   
   else if(front_sensor.identifica != 0){
     
      this->enemy_position = EnemyPosition::FRONT;
      this->latest_enemy_position = EnemyPosition::FRONT;

      return;
   }

   else if(left_sensor.identifica != 0){

    this->enemy_position = EnemyPosition::LEFT;
    this->latest_enemy_position = EnemyPosition::LEFT;

    return;
   }

   else if(full_left_sensor.identifica != 0){

    this->enemy_position = EnemyPosition::FULL_LEFT;
    this->latest_enemy_position = EnemyPosition::LEFT;

    return;
   }

   else if(right_sensor.identifica != 0){

    this->enemy_position = EnemyPosition::RIGHT;
    this->latest_enemy_position = EnemyPosition::RIGHT;

    return;
   }

   else if(full_right_sensor.identifica != 0){

    this->enemy_position = EnemyPosition::FULL_RIGHT;
    this->latest_enemy_position = EnemyPosition::RIGHT;
    
    return;
   }

   else if (latest_enemy_position == EnemyPosition::FULL_LEFT){

    this->enemy_position = EnemyPosition::SEARCH_LEFT;

    return;
   }
   
   else if(latest_enemy_position == EnemyPosition::FULL_RIGHT){
    
    this->enemy_position = EnemyPosition::SEARCH_RIGHT;

    return;
   }

}