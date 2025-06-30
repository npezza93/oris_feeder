#include "buttons.h"
#include "stepper.h"

ModulinoButtons buttons;

bool buttonPreviouslyPressed = false;

void loadButtons() {
  buttons.begin();
  buttons.setLeds(true, true, false);
}

void updateButtons() {
  buttons.update();

  bool buttonAPressed = buttons.isPressed(0);
  bool buttonBPressed = buttons.isPressed(1);

  if (buttonAPressed && !buttonPreviouslyPressed) {
    stepMotor(TOTAL_STEPS / 2, 0);
  }

  if (buttonBPressed && !buttonPreviouslyPressed) {
    stepMotor(TOTAL_STEPS / 2, 1);
  }

  buttonPreviouslyPressed = buttonAPressed || buttonBPressed;
}
