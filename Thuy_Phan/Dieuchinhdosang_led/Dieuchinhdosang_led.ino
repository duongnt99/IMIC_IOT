const int ledPin = 12;

// Cấu hình thông số PWM
const int freq = 5000;     // Tần số 5000Hz
const int resolution = 8;  // Độ phân giải 8-bit (0-255)

void setup() {
  ledcAttach(ledPin, freq, resolution);
}

void loop() {
  // Sáng dần lên
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    // Ở bản mới, ledcWrite dùng trực tiếp chân ledPin chứ không dùng "channel" nữa
    ledcWrite(ledPin, dutyCycle);
    delay(10);
  }

  // Tối dần đi
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledPin, dutyCycle);
    delay(10);
  }
}