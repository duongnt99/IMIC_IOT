#include <EEPROM.h>

#define EEPROM_SIZE 512

int cnt = 0;

void setup() {
  Serial.begin(9600);
  EEPROM.begin(EEPROM_SIZE);

  // Đọc số lần khởi động
  EEPROM.get(0, cnt);

  // Tăng lên 1
  cnt++;

  // Ghi lại
  EEPROM.put(0, cnt);
  EEPROM.commit();

  Serial.print("So lan khoi dong: ");
  Serial.println(cnt);
}

void loop() {
}