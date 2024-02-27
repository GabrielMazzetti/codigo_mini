#include <iostream>
#include "DigitalSensors.h"
#include <Arduino.h>

DigitalSensors::DigitalSensors(int pin){

  this->pin = pin;

}

int DigitalSensors::reading(){

   digitalRead(this->pin);

   if(digitalRead(this->pin) == 1){

      this->identifica = true;
   }

   else{

    this->identifica = false;
   }
    
    return identifica;

}