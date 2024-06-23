#ifndef PRATICE_H
#define PRATICE_H
#include "Arduino.h"

class Pratice{
   public: 
         void run_left();
         void run_right();
         int check_flag();
         void stop();
         void gpio_init();
         void move_left();
         void move_right();
         void evade();
         void park();
         void turn();
         static const int IR_PIN_1 = 12;
         static const int IR_PIN_2 = 8;
};

#endif
