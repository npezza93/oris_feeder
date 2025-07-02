#include <Wire.h>
#include <NTPClient.h>
#include "HX711.h"

#include "stepper.h"
#include "wifi.h"
#include "schedule.h"
#include "buttons.h"
#include "compartment.h"

NTPClient time_client(ntpUDP, "pool.ntp.org", -4 * 3600, 60000);  // Eastern Time (UTC-4)

Compartment compartment1(1, 52, 53, 28.0 / 28, 0);
Compartment compartment2(2, 54, 55, 28.0 / 28, 15000);
Compartment compartment3(3, 56, 57, 28.0 / 28, 30000);
Compartment compartment4(4, 58, 59, 28.0 / 28, 45000);
Compartment compartment5(5, 60, 61, 28.0 / 28, 60000);
Compartment compartment6(6, 62, 63, 28.0 / 28, 75000);
Compartment compartment7(7, 64, 65, 28.0 / 28, 90000);
Compartment compartment8(8, 66, 67, 28.0 / 28, 105000);
Compartment compartment9(9, 68, 69, 28.0 / 28, 120000);
Compartment compartment10(10, 70, 71, 28.0 / 28, 135000);
Compartment compartment11(11, 72, 73, 28.0 / 28, 150000);

Compartment* compartments[] = {
  &compartment1,
  &compartment2,
  &compartment3,
  &compartment4,
  &compartment5,
  &compartment6,
  &compartment7,
  &compartment8,
  &compartment9,
  &compartment10,
  &compartment11,
};
const int COMPARTMENT_COUNT = sizeof(compartments) / sizeof(compartments[0]);

const int FORWARD = 1;
const int BACKWARD = -1;

int current_position = 0;
int current_compartment = 0;
int current_direction = FORWARD;

void setup() {
  Serial.begin(57600);

  Modulino.begin();
  load_stepper();
  load_wifi();
  time_client.begin();
  time_client.update();

  load_buttons();

  load_current_feeding_time();

  for (int offset = 1; offset <= COMPARTMENT_COUNT; ++offset) {
    compartments[offset]->setup();
  }
}

void loop() {
  time_client.update();
  update_buttons();

  if (feeding_time_changed()) {
    set_current_feeding_time();

    int next_compartment = next_compartment_with_food();
    if (next_compartment != -1) {
      int step_delta = compartments[next_compartment]->steps - current_position;
      current_compartment = next_compartment;
      step_motor(abs(step_delta), step_delta > 0 ? 1 : -1);
    }
  }

  delay(1000);
}

int next_compartment_with_food() {
  for (int offset = current_compartment; offset < COMPARTMENT_COUNT && offset >= 0; offset += current_direction) {
    if (compartments[offset]->has_food()) {
      return offset;
    }
  }

  for (int offset = current_compartment; offset < COMPARTMENT_COUNT && offset >= 0; offset += (current_direction * -1)) {
    if (compartments[offset]->has_food()) {
      current_direction *= -1;
      return offset;
    }
  }

  return -1;
}
