#ifndef COMPARTMENT_H
#define COMPARTMENT_H

#include "HX711.h"

class Compartment {
public:
  int steps;

  Compartment(int n, int dout, int sck, float calibration, int num_steps)
      : name(n), dout_pin(dout), sck_pin(sck), calibration_factor(calibration),
        steps(num_steps) {}

  void setup() {
    scale.begin(dout_pin, sck_pin);
    scale.set_scale(calibration_factor);
    scale.tare();
  }

  float read() { return scale.get_units(20); }

  bool  has_food() {
    float weight = read();
    float lower_bound = TARGET_WEIGHT * (1.0 - THRESHOLD_PERCENT);
    float upper_bound = TARGET_WEIGHT * (1.0 + THRESHOLD_PERCENT);
    return weight >= lower_bound && weight <= upper_bound;
  }

private:
  static constexpr float TARGET_WEIGHT = 6.0;
  static constexpr float THRESHOLD_PERCENT = 0.20;

  int dout_pin, sck_pin, name;
  float calibration_factor;
  HX711 scale;
};

#endif
