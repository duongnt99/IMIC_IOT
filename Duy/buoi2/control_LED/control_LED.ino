void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  Serial.print("Hello World!\n");
  Serial.print("Hello ESP8266\n");
  Serial.print("1: ON\n");
  Serial.print("0: OFF\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    char data_read = Serial.read();
    if(data_read == '1'){
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(data_read == '0'){
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
