#ifndef SCALE_H
#define SCALE_H

#include "HX711.h"

class Scale {
public:
  Scale(int n, int dout, int sck, float calibration, int num_steps) : name(n), dout_pin(dout), sck_pin(sck), calibration_factor(calibration), steps(num_steps) {}

  void begin() {
    scale.begin(dout_pin, sck_pin);
    scale.set_scale(calibration_factor);
    scale.tare();
  }

  float read() {
    return scale.get_units(20);
  }

private:
  int dout_pin, sck_pin, name, steps;
  float calibration_factor;
  HX711 scale;
};

#endif
