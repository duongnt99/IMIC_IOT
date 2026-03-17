#include <Preferences.h>

Preferences preferences;

void setup() {
  Serial.begin(115200);
  Serial.println();

  // 1. Mở một "ngăn kéo" có tên là "kho-luu-tru"
  // Tham số thứ 2 là false nghĩa là chúng ta có quyền Đọc/Ghi (RW mode)
  preferences.begin("kho-luu-tru", false);

  // 2. Đọc giá trị có chìa khóa (key) tên là "counter"
  // Nếu chưa có (lần đầu chạy), nó sẽ lấy giá trị mặc định là 0
  unsigned int counter = preferences.getUInt("counter", 0);

  // Tăng biến đếm
  counter++;

  Serial.printf("Day la lan khoi dong thu: %u\n", counter);

  // 3. Lưu giá trị mới vào chìa khóa "counter"
  preferences.putUInt("counter", counter);

  // 4. Đóng ngăn kéo lại để giải phóng tài nguyên
  preferences.end();
  
  Serial.println("Du lieu da duoc tu dong luu vao NVS Flash!");
}

void loop() {
  
}