#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <Arduino.h>
#include <NTPClient.h>

extern NTPClient time_client;

struct FeedingTime {
  int hour;
  int minute;
};

int find_current_feeding_time();
void load_current_feeding_time();
bool feeding_time_changed();
void set_current_feeding_time();

#endif
