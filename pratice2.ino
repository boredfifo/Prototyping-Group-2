#include "ultrasonic.h"
#include "motor.h"
#include "pratice.h"
#include "color.h"

Ultrasonic praxis;
Pratice car;
Color color;

volatile int check_distance;
enum colors {OTHER_COLOR, RED, BLUE};
colors COLOR;

enum states {LINE_FOLLOWER, DETECTION, FAST};
states STATE;


void setup() {
  Serial.begin(9600);
  car.gpio_init();
  praxis.init();
  color.color_init();
}

void loop() {
  STATE = LINE_FOLLOWER;

  praxis.trigger();
  check_distance = praxis.distance(); 
  
 if(check_distance <= 4){
    car.stop();
    STATE = DETECTION;
    color_detection();
    }
    
  switch(STATE){
    case DETECTION: 
      switch(COLOR){
        case RED: 
            car.park();
            delay(5000);
            break;
        case BLUE:
            car.turn();
            delay(2000);
            break;
        case OTHER_COLOR:
          car.evade();
          delay(1000);
          break;
        }
      break;

     case LINE_FOLLOWER:
      line_follower();
      break;
    }
  
}

void line_follower(){
    car.run_right();
    car.run_left();
  }

void color_detection(){
  int red_value = color.red();
  int red_color = map(red_value, 47, 66, 255, 0);
  
  int blue_value = color.blue();
  int blue_color = map(blue_value, 85, 116, 255, 0);

  int other_value = color.green();
  int other_color = map(other_value, 95, 121, 255, 0);


  if(red_color > blue_color && red_color > other_color){
    COLOR = RED;
    Serial.println("red");
  }
  else if(blue_color > red_color && blue_color > other_color){
    COLOR = BLUE;
    Serial.println("blue");
    }
  else{
    COLOR = OTHER_COLOR;
    Serial.println("other color");
    }
    delay(1000);
  }

 
