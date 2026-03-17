#include "WiFi.h" // 

void setup() {
  Serial.begin(115200);

  // Set WiFi mode về Station
  WiFi.mode(WIFI_STA);

  // Ngắt kết nối cũ (nếu có)
  WiFi.disconnect();
  delay(100);

  Serial.println("ESP32 đã sẵn sàng quét mạng!");
}

void loop() {
  Serial.println("Đang quét...");

  // scanNetworks() trả về số lượng mạng tìm thấy
  int n = WiFi.scanNetworks();
  
  if (n == 0) {
    Serial.println("Không tìm thấy mạng Wi-Fi nào.");
  } else {
    Serial.print(n);
    Serial.println(" mạng tìm thấy:");
    for (int i = 0; i < n; ++i) {
      // In SSID, RSSI và Kênh (Channel)
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (Cường độ: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print("dBm) Ch:");
      Serial.print(WiFi.channel(i));
      
      // Kiểm tra bảo mật (ESP32 trả về kiểu int tương ứng với các chuẩn bảo mật)
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " [Mở]" : " [Bảo mật]");
      delay(10);
    }
  }
  Serial.println("");

  // Quét lại sau mỗi 30 giây
  delay(30000);
}