#include <iostream>
#include "AnalogSensors.h"
#include <Arduino.h>


AnalogSensors::AnalogSensors(int pin){

   this->pin1 = pin1;

}

int AnalogSensors::leitura(){

    analogRead(this->pin1);
    int valorBranco; //Valor que será definido nos testes

   if(analogRead(this->pin1) >= valorBranco){

      this->identificaBranco = true;
   }

   else{

    this->identificaBranco = false;
   }
    
    return identificaBranco;

}