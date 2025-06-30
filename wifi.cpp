#include "wifi.h"
#include "secrets.h"

WiFiUDP ntpUDP;

void loadWifi() {
  Serial.begin(9600);
  while (!Serial);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

}
