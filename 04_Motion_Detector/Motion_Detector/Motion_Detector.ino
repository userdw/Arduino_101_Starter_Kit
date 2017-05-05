#define LED_MODULE 9
#define PIR_MODULE 2

void fadeLED(int times) {
  for (int i = 0; i < times; i++) {
    for (int j = 255; j > 0; j--) {
      analogWrite(LED_MODULE, j);
      delay(1);
    }
    for (int j = 0; j < 256; j++) {
      analogWrite(LED_MODULE, j);
      delay(1);
    }
  }
}

void setup() {
  pinMode(LED_MODULE, OUTPUT);
  digitalWrite(LED_MODULE, HIGH);
  pinMode(PIR_MODULE, INPUT);
}

void loop() {
  while (digitalRead(PIR_MODULE)) {
    fadeLED(1);
  }
}
