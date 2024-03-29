#ifndef VISAO_H
#define VISAO_H
#include <Arduino.h>
#include "digitalSensors.h"
namespace EnemyPosition{


    enum Pos{
        
        LEFT,
        RIGHT,
        FRONT,
        FULL_LEFT,
        FULL_RIGHT,
        SEARCH_LEFT,
        SEARCH_RIGHT

    };
}

class Visao{

    public:
      EnemyPosition::Pos enemy_position;
      EnemyPosition::Pos latest_enemy_position;
      void updateEnemyPosition(DigitalSensors &front_sensor, DigitalSensors &full_left_sensor, 
      DigitalSensors &left_sensor, DigitalSensors &right_sensor, DigitalSensors&full_right_sensor);
      int esquerda;
      int direita;
      int ambos;  
      
};














#endif