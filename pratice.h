#ifndef PRATICE_H
#define PRATICE_H
#include "Arduino.h"

class Pratice{
   public: 
         void run_left();
         void run_right();
         void stop();
         void gpio_init();
         void move_left();
         void move_right();
         void movement();
         static const int IR_PIN_1 = 12;
         static const int IR_PIN_2 = 8;
};

#endif
