#ifndef COLOR_H
#define COLOR_H
#include "Arduino.h"

class Color{
	public: 
		void color_init();
		int red();
		int green();
		int blue();
    int off();
		static const int S0_PIN = A1;
		static const int S1_PIN = A2;
		static const int S2_PIN = A3;
		static const int S3_PIN = A4;
		static const int OUT_ENABLE = 10;

};

#endif
