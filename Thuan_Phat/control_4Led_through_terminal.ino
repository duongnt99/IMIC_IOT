#include <stdint.h>
#define RED_LED 4
#define YELLOW_LED 5
#define GREEN_LED 0
int led_list[] = {RED_LED, YELLOW_LED, GREEN_LED};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  for(int i = 0 ; i < 3 ; i++){
    pinMode(led_list[i], OUTPUT);
  }
  for(int i = 0 ; i < 3 ; i++){
    digitalWrite(led_list[i], LOW);
  }
}

void loop() {
  if(Serial.available() > 0){
    int c = Serial.read() - '0';
    if(c == 0){
      for(int i = 0 ; i < 3 ; i++){
        digitalWrite(led_list[i], LOW);
      }
    }
    else{
      digitalWrite(led_list[c - 1],HIGH);
    }
  }
  return;
}
