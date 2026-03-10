/*
* File: assigment1_led_control.ino
* Author:thuan phat
* Date: 2026-03-10
* Description: ESP8266 controls an Led through user commands from serial monotor
    Commands:
    - Type "led_on" to turn the Led on.
    - Type "led_off" to turn the Led off.
    - Type "blink_led" to toggle the led state per 500ms.
*/
String command = "";
enum LEDState{
  OFF,
  ON,
  BLINK
};

LEDState mode = OFF;


void setup() {
  Serial.begin(115200);             //Configure baudrate for serial monitor
  delay(2000);
  Serial.println();
  Serial.println("System is Ready!");
  pinMode(LED_BUILTIN, OUTPUT);     //Initialize the LED_BUILTIN as a output
  digitalWrite(LED_BUILTIN,HIGH);   // Turn the Led off at the beginning
}

void Blink_Led(){
  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  delay(500);
}


void loop() {
  if(Serial.available()){
    command = Serial.readStringUntil('\n');
    command.trim();
    if(command == "led_on"){
      mode = ON;
      Serial.println("Turn on the Led");
    }
    else if(command == "led_off"){
      mode = OFF;
      Serial.println("Turn off the Led");
    }
    else if(command == "blink_led"){
      mode = BLINK;
      Serial.println("Blink led");
    }
    else{
      Serial.println("UNDEFINED COMMAND");
    }
  }
  switch(mode){
    case(ON):
      digitalWrite(LED_BUILTIN,LOW);
      break;

    case(OFF):
      digitalWrite(LED_BUILTIN,HIGH);
      break;
    
    case(BLINK):
      Blink_Led();
      break;
  }
  return;
}
