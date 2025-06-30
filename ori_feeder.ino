#include <Wire.h>
#include <NTPClient.h>
#include "HX711.h"


#include "clock.h"
#include "stepper.h"
#include "wifi.h"
#include "compartments.h"
#include "buttons.h"
#include "scale.h"

NTPClient timeClient(ntpUDP, "pool.ntp.org", -4 * 3600, 60000);  // Eastern Time (UTC-4)

Scale scale1(1, 11, 12, 19526.0 / 28, 0);
Scale scale2(2, 13, 14, 28.0 / 28, 0);
Scale scale3(3, 15, 16, 28.0 / 28, 0);

void setup() {
  Modulino.begin();
  loadStepper();
  loadWifi();
  timeClient.begin();
  timeClient.update();

  loadClock();
  loadButtons();

  loadCurrentCompartment();

  Serial.begin(57600);
  scale1.begin();
  scale2.begin();
  scale3.begin();
}

void loop() {
  timeClient.update();
  updateButtons();
  updateCompartment();

  Serial.println(scale1.read(), 5);
  delay(1000);
}
