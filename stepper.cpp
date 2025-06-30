#include "stepper.h"

void load_stepper() {
  pinMode(DIRECTION_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(SLEEP_PIN, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);

  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, HIGH);
  digitalWrite(SLEEP_PIN, LOW);
}

void step_motor(int steps, int direction) {
  load_stepper();
  digitalWrite(DIRECTION_PIN, direction ? LOW : HIGH);
  digitalWrite(SLEEP_PIN, HIGH);

  delay(2);

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_DELAY);
  }
  digitalWrite(SLEEP_PIN, LOW);
}
