#include "buttons.h"
#include "stepper.h"

ModulinoButtons buttons;

bool button_previously_pressed = false;

void load_buttons() {
  buttons.begin();
  buttons.setLeds(true, true, false);
}

void update_buttons() {
  buttons.update();

  bool button_a_pressed = buttons.isPressed(0);
  bool button_b_pressed = buttons.isPressed(1);

  if (button_a_pressed && !button_previously_pressed) {
    step_motor(TOTAL_STEPS / 2, 0);
  }

  if (button_b_pressed && !button_previously_pressed) {
    step_motor(TOTAL_STEPS / 2, 1);
  }

  button_previously_pressed = button_a_pressed || button_b_pressed;
}
