#include "Arduino.h"
#include "color.h"


void Color::color_init(){
	pinMode(S0_PIN, OUTPUT);
	pinMode(S1_PIN, OUTPUT);
	pinMode(S2_PIN, OUTPUT);
	pinMode(S3_PIN, OUTPUT);
	pinMode(OUT_ENABLE, INPUT);

	digitalWrite(S0_PIN, HIGH); //scaling factor 20%
	digitalWrite(S1_PIN, LOW);
}

int Color::red(){
	digitalWrite(S3_PIN, LOW);
	digitalWrite(S2_PIN, LOW);
	digitalWrite(OUT_ENABLE, LOW);
	int red_value;
	red_value = pulseIn(OUT_ENABLE, LOW);
	return red_value;
}

int Color::green(){
	digitalWrite(S3_PIN, HIGH);
	digitalWrite(S2_PIN, HIGH);
	digitalWrite(OUT_ENABLE, LOW);
	int green_value;
	green_value = pulseIn(OUT_ENABLE, LOW);
	return green_value;
}

int Color::blue(){
	digitalWrite(S3_PIN, HIGH);
	digitalWrite(S2_PIN, LOW);
	digitalWrite(OUT_ENABLE, LOW);
	int blue_value;
	blue_value = pulseIn(OUT_ENABLE, LOW);
	return blue_value;
}

int Color::off(){
  digitalWrite(S3_PIN, LOW);
  digitalWrite(S2_PIN, HIGH);
  }
