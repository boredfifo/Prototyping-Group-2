#include "ultrasonic.h"
#include "Arduino.h"


void Ultrasonic::init(){
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}


void Ultrasonic::low(){
  digitalWrite(TRIG_PIN, LOW);
  }

void Ultrasonic::trigger(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(30);
  digitalWrite(TRIG_PIN, LOW);
}

int Ultrasonic::distance(){
    int counter = 0;
    int distance = 0;
    counter = pulseIn(ECHO_PIN, HIGH);
    distance = counter * 0.017;
    return distance;
  }
