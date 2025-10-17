#include "ESP32C3MiniLED.h"

ESP32C3MiniLED::ESP32C3MiniLED(uint8_t pin, uint8_t numPixels, uint8_t brightness)
  : _strip(numPixels, pin, NEO_GRB + NEO_KHZ800), _brightness(brightness) {}

void ESP32C3MiniLED::begin() {
    _strip.begin();
    _strip.setBrightness(_brightness);
    _strip.show(); // turn off
    indicateStartupSequence();
}

void ESP32C3MiniLED::indicateDataTransmission() {
    // short purple blink
    setColor(128, 0, 128, 200);
    setColor(0, 0, 0, 100);
}

void ESP32C3MiniLED::indicateStartupSequence() {
    // red -> blue -> orange -> violet
    setColor(255, 0, 0, 400);     // Red
    setColor(0, 0, 255, 400);     // Blue
    setColor(255, 165, 0, 400);   // Orange
    setColor(148, 0, 211, 400);   // Violet
    setColor(0, 0, 0, 0);         // Off
}

void ESP32C3MiniLED::setColor(uint8_t r, uint8_t g, uint8_t b, uint16_t ms) {
    _strip.setPixelColor(0, _strip.Color(r, g, b));
    _strip.show();
    if (ms) delay(ms);
}