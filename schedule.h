#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <Arduino.h>
#include <NTPClient.h>

extern NTPClient timeClient;

struct FeedingTime {
  int hour;
  int minute;
};

int find_current_feeding_time();
void load_current_feeding_time();
void set_current_feeding_time(int index);
void update_feeding_time();

#endif
