#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor{
	public: 
		void motor_init();
    void move_forward();
		void move_forward_left();
    void move_forward_right();
    void stop();
    void stop_left();
    void stop_right();
		void left();
    void right();
   static const int EN_A = 3;
   static const int EN_B = 11;
   static const int MOTOR_PIN_1 = 4;
   static const int MOTOR_PIN_2 = 5;
   static const int MOTOR_PIN_3 = 6;
   static const int MOTOR_PIN_4 = 7;

};




#endif
