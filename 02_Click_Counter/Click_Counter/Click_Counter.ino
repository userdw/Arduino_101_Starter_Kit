#define LED_MODULE 9
#define DIGITAL_PUSH_BUTTON 2
#define DEBOUNCE_DELAY 80
#define TOGGLE_EXECUTE_DELAY 1500

unsigned long lastDebounceTime = 0;
unsigned long lastBlinkExecuteDelay = 0;
byte blinkTimes = 0;

void toggleLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_MODULE, !digitalRead(LED_MODULE));
    delay(250);
    digitalWrite(LED_MODULE, !digitalRead(LED_MODULE));
    delay(250);
  }
}

void setup() {
  pinMode(LED_MODULE, OUTPUT);
  pinMode(DIGITAL_PUSH_BUTTON, INPUT);
}

void loop() {
  if (digitalRead(DIGITAL_PUSH_BUTTON) == LOW) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    lastDebounceTime = millis();
    lastBlinkExecuteDelay = millis();
    blinkTimes++;
    if (blinkTimes > 5) {
      blinkTimes = 5;
    }
  }

  if ((millis() - lastBlinkExecuteDelay) > TOGGLE_EXECUTE_DELAY) {
    toggleLED(blinkTimes);
    blinkTimes = 0;
    lastBlinkExecuteDelay = millis();
  }
}
