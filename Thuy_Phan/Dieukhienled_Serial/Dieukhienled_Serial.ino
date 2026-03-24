const int ledPins[] = {12, 14, 27, 26};

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); 
  }
  Serial.println("Nhap tu 1-4 de bat LED, 0 de tat het:");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    if (input >= '1' && input <= '4') {
      int index = input - '1'; 
      digitalWrite(ledPins[index], HIGH);
      Serial.print("Da bat LED "); Serial.println(input);
    } 
    else if (input == '0') {
      for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
      }
      Serial.println("Da tat toan bo LED");
    }
  }
}