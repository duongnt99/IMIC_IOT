#define khoang_thoi_gian 2000
#define LED_PIN 2
unsigned long previous_time = 0;  // Lưu thời điểm bắt đầu
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("START COUNTING...");
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current_time = millis(); // Lấy thời gian hiện tại
  if (current_time - previous_time >= khoang_thoi_gian){
    previous_time = current_time; // lưu lại mốc hiên tại
    Serial.print("Excution time: ");
    Serial.print(current_time/1000);
    Serial.println(" s");
  }
}
