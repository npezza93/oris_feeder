#include "schedule.h"
#include "stepper.h"

const FeedingTime times[] = {
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
int current_feeding_time;

int find_current_feeding_time() {
  timeClient.update();

  int current_hour = timeClient.getHours();
  int current_minute = timeClient.getMinutes();
  int current_minutes = current_hour * 60 + current_minute;

  int closest_index = -1;
  int latest_seen   = -1;

  int count = sizeof(times) / sizeof(times[0]);

  for (int i = 0; i < count; ++i) {
    int comp_minutes = times[i].hour * 60 + times[i].minute;

    if (comp_minutes <= current_minutes && comp_minutes > latest_seen) {
      latest_seen   = comp_minutes;
      closest_index = i;
    }
  }

  if (closest_index == -1) {
    closest_index = count - 1;
  }

  return closest_index;
}

void load_current_feeding_time() {
  set_current_feeding_time(find_current_feeding_time());
}

void update_feeding_time() {
  int time = find_current_feeding_time();
  if (time != current_feeding_time) {
    stepMotor(TOTAL_STEPS / 2, 0);
    set_current_feeding_time(time);
  }
}

void set_current_feeding_time(int index) {
  current_feeding_time = index;
  Serial.println(current_feeding_time, 5);
}
