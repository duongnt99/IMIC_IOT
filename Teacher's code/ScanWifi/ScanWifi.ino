#include "ESP8266WiFi.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // Đặt ÉP8266 ở chế độ Station (VĐK sẽ như một chiếc điện thoại đi dò Wifi)
  WiFi.mode(WIFI_STA);
  //Ngắt kết nối mạng cũ
  WiFi.disconnect();
  delay(1000);

  Serial.println("Start scan wifi...");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Scanning wifi...");
  //Trả về số lượng wifi tìm thấy
  int number_wifi = WiFi.scanNetworks();
  if(number_wifi == 0)
  {
    Serial.println("Not found");
  }
  else
  {
    Serial.print("Found");
    Serial.println(number_wifi);

    for(int i=0; i < number_wifi; i++){
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i)); //Tên mạng
      Serial.print(" Strength: ");
      Serial.print(WiFi.RSSI(i)); //Tín hiệu
      Serial.println(" dBm");
      delay(10);
    }
  }

  Serial.println("Wait 5s for rescanning...");
  delay(5000);
}
