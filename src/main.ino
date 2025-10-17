#include <ESP32C3MiniLED.h>

#define RGB_LED_PIN 8

ESP32C3MiniLED led(RGB_LED_PIN);

void setup() {
  led.begin();
}

void loop() {
  led.indicateDataTransmission();
  delay(5000); // Simulate data transmission every second
}