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

void Motor::move_forward(){
    analogWrite(EN_A, 80);
    analogWrite(EN_B, 80);
    digitalWrite(MOTOR_PIN_1, HIGH);
    digitalWrite(MOTOR_PIN_2, LOW);
    digitalWrite(MOTOR_PIN_3, LOW);
    digitalWrite(MOTOR_PIN_4, HIGH );
  }

void Motor::stop(){
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, LOW);
  digitalWrite(MOTOR_PIN_1, LOW);
  }

void Motor::move_forward_left(){
    analogWrite(EN_B, 80);
    digitalWrite(MOTOR_PIN_3, LOW);
    digitalWrite(MOTOR_PIN_4, HIGH);
}

void Motor::move_forward_right(){
    analogWrite(EN_A, 80);
    digitalWrite(MOTOR_PIN_1, HIGH);
    digitalWrite(MOTOR_PIN_2, LOW);
}

void Motor:: stop_left(){
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, LOW);
}
void Motor::stop_right(){
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_1, LOW);
  }

void Motor::right(){
  analogWrite(EN_A, 80);
  analogWrite(EN_B, 80);
  digitalWrite(MOTOR_PIN_1, LOW);
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, HIGH);
  }
    
void Motor::left(){
  analogWrite(EN_A, 80);
  analogWrite(EN_B, 80);
  digitalWrite(MOTOR_PIN_1, HIGH);
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, LOW);
  }
 
