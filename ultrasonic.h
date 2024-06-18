#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include "Arduino.h"
#include "Servo.h"

class Ultrasonic{
	public:
		void init();
		void move_left();
    void move_right();
    void trigger();
		static const int SERVO_PIN = 9;
    static const int ECHO_PIN = 2;
    static const int TRIG_PIN = 11;
};


#endif
