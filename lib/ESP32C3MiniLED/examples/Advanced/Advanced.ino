#include <ESP32C3MiniLED.h>

#define RGB_LED_PIN 8

ESP32C3MiniLED led(RGB_LED_PIN, 1, 100); // Higher brightness (100 instead of default 50)

void setup() {
  Serial.begin(115200);
  led.begin();
  Serial.println("LED Control Example Started");
}

void loop() {
  Serial.println("Simulating data transmission...");
  led.indicateDataTransmission();
  
  Serial.println("Waiting 2 seconds...");
  delay(2000);
  
  Serial.println("Running startup sequence again...");
  led.indicateStartupSequence();
  
  Serial.println("Waiting 3 seconds before next cycle...");
  delay(3000);
}