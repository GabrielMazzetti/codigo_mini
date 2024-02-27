#ifndef ANALOGSENSORS_H
#define ANALOGSENSORS_H


#include <iostream>
#include <Arduino.h>

class AnalogSensors{
     
     public:

     int pin1;
     AnalogSensors(int pin1);   
     bool identificaBranco;
     int leitura();

     private:


};















#endif