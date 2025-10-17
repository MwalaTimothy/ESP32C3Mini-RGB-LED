#ifndef ESP32C3MINILED_H
#define ESP32C3MINILED_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class ESP32C3MiniLED {
public:
    ESP32C3MiniLED(uint8_t pin, uint8_t numPixels = 1, uint8_t brightness = 50);
    void begin();
    void indicateDataTransmission(); // optional short purple blink
    void indicateStartupSequence();  // called from begin()

private:
    Adafruit_NeoPixel _strip;
    uint8_t _brightness;
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint16_t ms = 0);
};

#endif