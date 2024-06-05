#include "Arduino.h"
#include "pratice.h"
#include "motor.h"
#include "ultrasonic.h"

Motor motors;
Ultrasonic nnew;

void Pratice::gpio_init(){
    motors.motor_init();
    pinMode(IR_PIN_1, INPUT);
    pinMode(IR_PIN_2, INPUT);
}

void Pratice::run_left(){
 if(digitalRead(IR_PIN_1) == HIGH){
       motors.stop_left();
   }
  else{
      motors.move_forward_left();
    }
}

void Pratice::run_right(){
 if(digitalRead(IR_PIN_2) == HIGH){
       motors.stop_right();
   }
  else{
      motors.move_forward_right();
    }
}

void Pratice::stop(){
  motors.stop_left();
  motors.stop_right();
  }

void Pratice::movement(){
  motors.left();
  delay(1000);
  motors.move_forward();
  delay(2000);
  motors.right();
  delay(1000);
  motors.move_forward();
  delay(20000);
  }

 
