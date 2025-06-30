#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>
#include <NTPClient.h>
#include <Arduino_LED_Matrix.h>

extern byte Time[8][12];
extern byte Digits[5][30];
extern NTPClient timeClient;

void displayDigit(int d, int sx, int sy);
void renderClock();
void loadClock();

#endif
