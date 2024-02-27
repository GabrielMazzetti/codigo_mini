#include <iostream>
#include "analogSensors.h"
#include <Arduino.h>


AnalogSensors::AnalogSensors(int pin1){

   this->pin1 = pin1;

}

int AnalogSensors::leitura(){

    analogRead(this->pin1);
    int valorBranco;
    valorBranco = 540; //valor não testado

   if(analogRead(this->pin1) >= valorBranco){

      this->identificaBranco = true;
   }

   else{

    this->identificaBranco = false;
   }
    
    return identificaBranco;

}