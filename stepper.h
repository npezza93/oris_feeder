#ifndef STEPPER_H
#define STEPPER_H

#include <Arduino.h>
#include <Modulino.h>

constexpr int TOTAL_STEPS = 163200;

void loadStepper();
void stepMotor(int steps, int direction);

#endif
