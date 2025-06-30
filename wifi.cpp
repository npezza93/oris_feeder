#include "wifi.h"
#include "secrets.h"

WiFiUDP ntpUDP;

void load_wifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
