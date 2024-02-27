#include <Arduino.h>
#include "Visao.h"
#include "DigitalSensors.h"
#include <iostream>
using namespace std;

void Visao::updateEnemyPosition(DigitalSensors &front_sensor, DigitalSensors &full_left_sensor, 
DigitalSensors &left_sensor, DigitalSensors &right_sensor, DigitalSensors&full_right_sensor){

   if(front_sensor.identifica != 0){
     
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
    this->latest_enemy_position = EnemyPosition::SEARCH_LEFT;

    return;
   }

   else if(right_sensor.identifica != 0){

    this->enemy_position = EnemyPosition::RIGHT;
    this->latest_enemy_position = EnemyPosition::RIGHT;

    return;
   }

   else if(full_right_sensor.identifica != 0){

    this->enemy_position = EnemyPosition::FULL_RIGHT;
    this->latest_enemy_position = EnemyPosition::SEARCH_RIGHT;
    
    return;
   }


}