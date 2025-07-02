#include <Wire.h>
#include <NTPClient.h>
#include "HX711.h"

#include "stepper.h"
#include "wifi.h"
#include "schedule.h"
#include "buttons.h"
#include "scale.h"

NTPClient time_client(ntpUDP, "pool.ntp.org", -4 * 3600, 60000);  // Eastern Time (UTC-4)

Scale scale1(1, 52, 53, 19526.0 / 28, 0);
Scale scale2(2, 13, 14, 28.0 / 28, 0);
Scale scale3(3, 15, 16, 28.0 / 28, 0);

void setup() {
  Serial.begin(57600);

  Modulino.begin();
  load_stepper();
  load_wifi();
  time_client.begin();
  time_client.update();

  load_buttons();

  load_current_feeding_time();

  scale1.begin();
  scale2.begin();
  scale3.begin();
}

void loop() {
  time_client.update();
  update_buttons();

  Serial.println(scale1.read(), 5);
  delay(1000);
}
