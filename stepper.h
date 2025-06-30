#ifndef STEPPER_H
#define STEPPER_H

#include <Arduino.h>
#include <Modulino.h>

const int TOTAL_STEPS = 163200;
const int DIRECTION_PIN = 2;
const int STEP_PIN = 3;
const int SLEEP_PIN = 4;
const int STEP_DELAY = 50;

const int MS1 = 5;
const int MS2 = 6;
const int MS3 = 7;

void load_stepper();
void step_motor(int steps, int direction);

#endif
