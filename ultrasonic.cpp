#include "ultrasonic.h"
#include "Arduino.h"
#include "Servo.h"

Servo servo1; 

void Ultrasonic::init(){
	//servo1.attach(SERVO_PIN);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void Ultrasonic::move_left(){
  int Position = 0;
	for(Position = 0; Position <= 90; Position ++){
		servo1.write(Position);
		delay(10);
	}
  for(Position = 90; Position >= 0; Position --){
		servo1.write(Position);
		delay(10);
	}
}
void Ultrasonic::move_right(){
  int Position1 = 90;
	for(Position1 = 90; Position1 <= 180; Position1 ++){
		servo1.write(Position1);
		delay(10);
	}
  for(Position1 = 180; Position1 >= 90; Position1 --){
		servo1.write(Position1);
		delay(10);
	}
}



void Ultrasonic::trigger(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(50);
  digitalWrite(TRIG_PIN, LOW);
}
