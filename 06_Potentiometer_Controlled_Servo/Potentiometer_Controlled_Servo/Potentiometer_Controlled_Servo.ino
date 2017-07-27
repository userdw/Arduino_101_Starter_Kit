#include <Servo.h>
#define SERVO 6
#define ROTATION_SENSOR A0

Servo sg90;

void setup() {
  sg90.attach(SERVO);
}

void loop() {
  int rotationData = analogRead(A0);
  rotationData = map(rotationData, 0, 1023, 0, 180);
  sg90.write(rotationData);
}
