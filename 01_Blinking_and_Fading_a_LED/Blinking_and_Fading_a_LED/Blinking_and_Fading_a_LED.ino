#define LED_MODULE 9

void toggleLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_MODULE, !digitalRead(LED_MODULE));
    delay(250);
    digitalWrite(LED_MODULE, !digitalRead(LED_MODULE));
    delay(250);
  }
}

void fadeLED(int times) {
  for (int i = 0; i < times; i++) {
    for (int j = 0; j < 256; j++) {
      analogWrite(LED_MODULE, j);
      delay(1);
    }
    for (int j = 255; j >= 0; j--) {
      analogWrite(LED_MODULE, j);
      delay(1);
    }
  }
}

void setup() {
  pinMode(LED_MODULE, OUTPUT);
  digitalWrite(LED_MODULE, HIGH);
}

void loop() {
  toggleLED(4);
  delay(1000);
  fadeLED(4);
  delay(1000);
}
