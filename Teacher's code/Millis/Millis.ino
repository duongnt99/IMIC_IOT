unsigned long start_time = 0;
const long duration = 2000; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);
  Serial.println("Start counting...");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Lấy thời gian hiện tại từ lúc board chạy
  unsigned long current_time = millis();

  // Kiểm tra xem là đã trôi qua đủ 2s chưa
  if(current_time - start_time >= duration){
    // Lưu mốc hiện tại
    start_time = current_time;

    // In ra màn hình thời gian đã chạy
    Serial.print("Excution time: ");
    Serial.print(current_time/1000);
    Serial.println("s");
  }
  // ở đây, board sẽ không bị ngủ như là dùng delay
  // Có thể thêm code nhận tín hiệu, đọc nút nhấn ... Thoải mái mà không bị ảnh hưởng
}
