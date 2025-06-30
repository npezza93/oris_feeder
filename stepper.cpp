#include "stepper.h"

ModulinoBuzzer buzzer;

const int directionPin = 2;
const int stepPin = 3;
const int sleepPin = 4;
const int stepDelayMicros = 50;

const int ms1 = 8;
const int ms2 = 9;
const int ms3 = 10;

void loadStepper() {
  buzzer.begin();
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(sleepPin, OUTPUT);
  pinMode(ms1, OUTPUT);
  pinMode(ms2, OUTPUT);
  pinMode(ms3, OUTPUT);

  digitalWrite(ms1, HIGH);
  digitalWrite(ms2, HIGH);
  digitalWrite(ms3, HIGH);
  digitalWrite(sleepPin, LOW);
}

void stepMotor(int steps, int direction) {
  loadStepper();
  digitalWrite(directionPin, direction ? LOW : HIGH);
  digitalWrite(sleepPin, HIGH);

  delay(2);

  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelayMicros);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelayMicros);
  }
  digitalWrite(sleepPin, LOW);

  int noteDuration = 150;

  // Notes: E E - E - C E G - G
  buzzer.tone(659, noteDuration);  // E5
  delay(noteDuration);
  buzzer.noTone();
  delay(noteDuration / 2);

  buzzer.tone(659, noteDuration);  // E5
  delay(noteDuration);
  buzzer.noTone();
  delay(noteDuration / 2);

  buzzer.tone(659, noteDuration);  // E5
  delay(noteDuration);
  buzzer.noTone();
  delay(noteDuration);

  buzzer.tone(523, noteDuration);  // C5
  delay(noteDuration);
  buzzer.noTone();
  delay(noteDuration / 2);

  buzzer.tone(659, noteDuration);  // E5
  delay(noteDuration);
  buzzer.noTone();
  delay(noteDuration / 2);

  buzzer.tone(784, noteDuration);  // G5
  delay(noteDuration * 1.5);
  buzzer.noTone();
}
