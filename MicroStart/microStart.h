#ifndef MicroStart_H
#define MicroStart_H
#include <Arduino.h>

namespace uStartState{

    enum States{
       
       START,
       STOP

    };   

}


class uStart{

    public:
      int signal_pin;
      uStartState::States state;
      void update();
      uStart(int signal_pin);

};


#endif