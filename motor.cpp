#include "motor.h"
#include "Arduino.h"



void Motor::motor_init(){
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(MOTOR_PIN_3, OUTPUT);
  pinMode(MOTOR_PIN_4, OUTPUT);
}

void Motor::move_forward(int speed){
    analogWrite(EN_A, speed);
    analogWrite(EN_B, speed);
    digitalWrite(MOTOR_PIN_1, HIGH);
    digitalWrite(MOTOR_PIN_2, LOW);
    digitalWrite(MOTOR_PIN_3, LOW);
    digitalWrite(MOTOR_PIN_4, HIGH );
  }

 void Motor::move_backward(int speed){
    analogWrite(EN_A, speed);
    analogWrite(EN_B, speed);
    digitalWrite(MOTOR_PIN_1, LOW);
    digitalWrite(MOTOR_PIN_2, HIGH);
    digitalWrite(MOTOR_PIN_3, HIGH);
    digitalWrite(MOTOR_PIN_4, LOW );
  }

void Motor::stop(){
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, LOW);
  digitalWrite(MOTOR_PIN_1, LOW);
  }

void Motor::move_forward_left(int speed){
    analogWrite(EN_A, speed);
    analogWrite(EN_B, speed);
    digitalWrite(MOTOR_PIN_3, LOW);
    digitalWrite(MOTOR_PIN_4, HIGH);
}

void Motor::move_backward_left(int speed){
    analogWrite(EN_A, speed);
    analogWrite(EN_B, speed);
    digitalWrite(MOTOR_PIN_3, HIGH);
    digitalWrite(MOTOR_PIN_4, LOW);
  }

void Motor::move_forward_right(int speed){
    analogWrite(EN_A, speed);
    analogWrite(EN_B, speed);
    digitalWrite(MOTOR_PIN_1, HIGH);
    digitalWrite(MOTOR_PIN_2, LOW);
}

void Motor::move_backward_right(int speed){
    analogWrite(EN_A, speed);
    analogWrite(EN_B, speed);
    digitalWrite(MOTOR_PIN_1, LOW);
    digitalWrite(MOTOR_PIN_2, HIGH);
  }

void Motor:: stop_left(){
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, LOW);
}
void Motor::stop_right(){
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_1, LOW);
  }

void Motor::right(int speed){
  analogWrite(EN_A, speed);
  analogWrite(EN_B, speed);
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, HIGH);
  }
    
void Motor::left(int speed){
  analogWrite(EN_A, speed);
  analogWrite(EN_B, speed);
  digitalWrite(MOTOR_PIN_1, HIGH);
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, LOW);
  }
 
