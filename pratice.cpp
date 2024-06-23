#include "Arduino.h"
#include "pratice.h"
#include "motor.h"
#include "ultrasonic.h"

Motor motors;

void Pratice::gpio_init(){
    motors.motor_init();
    pinMode(IR_PIN_1, INPUT);
    pinMode(IR_PIN_2, INPUT);
}

int Pratice::check_flag(){
  int flag = 0;
  if(digitalRead(IR_PIN_1) == LOW || digitalRead(IR_PIN_2) == LOW){
     flag = 1;
    }
    return flag;
  }

void Pratice::run_left(){
 if(digitalRead(IR_PIN_1) == HIGH){
       motors.stop_left();
   }
  else{
      motors.move_forward_left(80);
    }
}

void Pratice::run_right(){
 if(digitalRead(IR_PIN_2) == HIGH){
       motors.stop_right();
   }
  else{
      motors.move_forward_right(80);
    }
}

void Pratice::stop(){
  motors.stop_left();
  motors.stop_right();
  }

void Pratice::evade(){
  motors.move_backward(100);
  delay(1000);
  motors.left(100);
  delay(1000);
  motors.move_forward(100);
  delay(1000);
  motors.right(100);
  delay(1000);
  motors.move_forward(100);
  delay(1000);
  motors.right(100);
  delay(700);
  motors.stop();
  delay(500);
  }

void Pratice::park(){
  motors.move_backward(100);
  delay(1000);
  motors.right(100);
  delay(1000);
  motors.move_forward(100);
  delay(1000);
  motors.left(100);
  delay(1000);
  motors.stop();
  delay(5000);
  motors.move_forward(100);
  delay(1000);
  motors.left(100);
  delay(500);
  motors.stop();
  delay(1000);
  }

 void Pratice::turn(){
  motors.move_backward_left(100);
  motors.move_forward_right(100);
  delay(1900);
  motors.stop();
  delay(500);
  }

 
