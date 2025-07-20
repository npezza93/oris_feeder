#include "knob.h"
#include "stepper.h"

ModulinoKnob knob;

int current_knob_position;

void load_knob() {
  knob.begin();
  current_knob_position = knob.get();
}

void update_knob() {
  int position = knob.get();

  if (position != current_knob_position) {
    int steps = (position - current_knob_position);
    step_motor((TOTAL_STEPS / 200) * abs(steps), steps > 0 ? 0 : 1);

    current_knob_position = position;
  }
}
