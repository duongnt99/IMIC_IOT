#include <EEPROM.h> 

int check = 0; 
int eepromAddress = 0; 

void setup() {
  Serial.begin(115200);
  delay(1000); 
  Serial.println("Start...");

  EEPROM.begin(512);

  EEPROM.get(eepromAddress, check);

  if (check < 0 || check > 10000) {
    check = 0; 
  }

  Serial.print("So lan khoi dong truoc do: ");
  Serial.println(check);

  // Tăng biến đếm lên 1 cho lần khởi động này
  check++;

  Serial.print("So lan khoi dong hien tai: ");
  Serial.println(check);

  // BƯỚC 3: Lưu giá trị vào bộ nhớ
  EEPROM.put(eepromAddress, check); // Ghi giá trị mới vào buffer
  EEPROM.commit();                      // LỆNH QUAN TRỌNG: Ghi thực sự vào Flash

  Serial.println("Da luu vao FLASH thanh cong!");
}

void loop() {
  // Trong bài tập này, chúng ta chỉ đếm số lần khởi động (setup) 
  // nên không cần viết gì trong vòng lặp loop()
}