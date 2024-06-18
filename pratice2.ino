#include "ultrasonic.h"
#include "motor.h"
#include "pratice.h"
#include "color.h"

Ultrasonic ultrasonic;
Pratice car;
Color color;

volatile int check_distance;
volatile int flag;
enum colors {OTHER_COLOR, RED, BLUE};
colors COLOR;

enum states {IDLE, LINE_FOLLOWER, DETECTION};
states STATE;


void setup() {
  Serial.begin(9600);
  car.gpio_init();
  ultrasonic.init();
  color.color_init();
}

void loop() {
  STATE = IDLE;
  flag = car.check_flag();
  if(flag == 1){
    STATE = LINE_FOLLOWER;
    }
    
  ultrasonic.trigger();
  check_distance = ultrasonic.distance(); 
  
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

     case IDLE:
       car.stop();
       ultrasonic.low();
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
  }
  else if(blue_color > red_color && blue_color > other_color){
    COLOR = BLUE;
    }
  else{
    COLOR = OTHER_COLOR;
    }
    delay(1000);
  }
