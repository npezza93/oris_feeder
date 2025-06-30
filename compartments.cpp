#include "compartments.h"
#include "stepper.h"
#include "clock.h"

const Compartment compartments[] = {
  {1, 30},
  {3, 50},
  {6, 30},
  {8, 30},
  {11, 0},
  {13, 0},
  {15, 0},
  {17, 0},
  {19, 0}
};
int currentCompartment;

int findCurrentCompartment() {
  timeClient.update();

  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  int currentMinutes = currentHour * 60 + currentMinute;

  int closestIndex = -1;
  int latestSeen   = -1;

  int count = sizeof(compartments) / sizeof(compartments[0]);

  for (int i = 0; i < count; ++i) {
    int compMinutes = compartments[i].hour * 60 + compartments[i].minute;

    if (compMinutes <= currentMinutes && compMinutes > latestSeen) {
      latestSeen   = compMinutes;
      closestIndex = i;
    }
  }

  if (closestIndex == -1) {
    closestIndex = count - 1;
  }

  return closestIndex;
}

void loadCurrentCompartment() {
  setCurrentCompartment(findCurrentCompartment());
}

void updateCompartment() {
  int compartment = findCurrentCompartment();
  if (compartment != currentCompartment) {
    stepMotor(TOTAL_STEPS / 2, 0);
    setCurrentCompartment(compartment);
  }
}

void setCurrentCompartment(int index) {
  currentCompartment = index;
  displayDigit(currentCompartment, 0, 0);
}
