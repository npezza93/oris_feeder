#ifndef COMPARTMENTS_H
#define COMPARTMENTS_H

#include <Arduino.h>
#include <NTPClient.h>

extern NTPClient timeClient;

struct Compartment {
  int hour;
  int minute;
  int slot;
  int weight;
};

int findCurrentCompartment();
void loadCurrentCompartment();
void setCurrentCompartment(int index);
void updateCompartment();

#endif
