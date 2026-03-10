#include <ESP8266WiFi.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);

  // Đặt chế độ Station
  WiFi.mode(WIFI_STA);

  Serial.println("INFORMATION");

  Serial.println(WiFi.macAddress());
}

void loop() {
  // put your main code here, to run repeatedly:

}
