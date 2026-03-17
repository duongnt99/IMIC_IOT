#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  WiFi.disconnect();
  
  delay(1000);

  Serial.println("START SCAN WIFI!!!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Scanning WiFi...");
  int number_wifi = WiFi.scanNetworks();
  if(number_wifi == 0){
    Serial.println("Not Found");
  }
  else{
    Serial.print(number_wifi);
    Serial.print(" WiFi networks detected!\n");
    for(int i=0; i<number_wifi; i++){
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(", Strength: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print("dBm\n");
    }
  }
  Serial.println("Wait for 5 second....");
  delay(5000);
}
