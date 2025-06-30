#include "wifi.h"
#include "secrets.h"

WiFiUDP ntpUDP;

void loadWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
