void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // Tắt đèn ban đầu

  Serial.begin(115200);
  delay(1000);
  Serial.println(" '1' for turn on, '0' for turn off ");

}

void loop() {
  // put your main code here, to run repeatedly:
  // Kiểm tra dữ liệu từ máy tính gửi xuống
  if( Serial.available() > 0 )
  {
    // Đọc ký tự vừa nhận được
    char string_input = Serial.read();

    if(string_input == '1')
    {
      digitalWrite(LED_BUILTIN, LOW); //Bật đèn
      Serial.println("Turn on led");
    }

    if(string_input == '0')
    {
      digitalWrite(LED_BUILTIN, HIGH); //Bật đèn
      Serial.println("Turn off led");
    }
  }
}
