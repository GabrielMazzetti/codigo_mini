#ifndef DigitalSensors_H
#define DigitalSensors_H

#include <iostream>
#include <Arduino.h>

class DigitalSensors{
     
     public:

     int pin;
     DigitalSensors(int pin);   
     bool identifica;
     int reading();

     private:


};


#endif