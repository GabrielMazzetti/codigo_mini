#include <iostream>
#include <Arduino.h>
#include "MicroStart.h"

using namespace std;


uStart::uStart(int signal_pin){

    this->signal_pin = signal_pin;
    this->state = uStartState::STOP;
}

void uStart::update(){

   bool leitura = digitalRead(this->signal_pin);

   if(leitura == 0)
     this->state = uStartState::STOP;

   else 
     this->state = uStartState::START;  
     
}