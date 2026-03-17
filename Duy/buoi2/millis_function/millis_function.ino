unsigned long start_time = 0;
const long duration = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("Start counting...");
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current_time = millis();
  if(current_time - start_time >= duration){
    start_time = current_time;
    Serial.print("Excution time: ");
    Serial.print(current_time/1000);
    Serial.println("s");
  }
}
