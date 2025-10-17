# ESP32C3Mini RGB LED Library

[![Platform: ESP32-C3](https://img.shields.io/badge/Platform-ESP32--C3-blue)](https://www.espressif.com/en/products/socs/esp32-c3)
[![Framework: Arduino](https://img.shields.io/badge/Framework-Arduino-green)](https://www.arduino.cc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A lightweight Arduino library for controlling the onboard RGB LED (NeoPixel) on ESP32-C3 Mini development boards. Provides simple functions for visual feedback including startup sequence and data transmission indication.

## Quick API
- ESP32C3MiniLED(uint8_t pin, uint8_t numPixels = 1, uint8_t brightness = 50)
- void begin()
- void indicateDataTransmission()   // short purple blink
- void indicateStartupSequence()    // startup sequence (already called from begin())

## Installation

PlatformIO (recommended)
- Option A — local lib (current repo layout): project root contains `lib/C3_RGB_Library/` (library source) and `src/main.ino` (test sketch). PlatformIO will auto-detect the local library.
- Option B — lib_deps (global): add to `platformio.ini`
  ```ini
  lib_deps = adafruit/Adafruit NeoPixel
  ```
Arduino IDE
- Copy the `C3_RGB_Library` folder into your Arduino `libraries/` folder. Restart the IDE.

Notes
- The library depends on Adafruit NeoPixel for WS2812-style LEDs.

## Usage (minimal)
Include the header, define the pin, instantiate the object, then call begin() in setup().

```cpp
#include <ESP32C3MiniLED.h>

#define RGB_LED_PIN 7

ESP32C3MiniLED led(RGB_LED_PIN); // default: 1 pixel, brightness 50 (0-255)

void setup() {
  led.begin(); // runs startup sequence automatically
}

void loop() {
  // your main code
  led.indicateDataTransmission(); // call when sending data
  delay(1000);
}
```

## Integrate into your codebase
If you need to indicate transmission from elsewhere in your program, keep a single global instance and call its method from any module.

Example: call from a function that transmits data
```cpp
// main.ino
#include <ESP32C3MiniLED.h>
#define RGB_LED_PIN 7
ESP32C3MiniLED led(RGB_LED_PIN);

void setup() {
  led.begin();
}

void loop() {
  sendTelemetry();
  delay(1000);
}

// telemetry.cpp / telemetry.h can call led.indicateDataTransmission()
// telemetry.cpp (same translation unit or include extern if split)
void sendTelemetry() {
  // ... your code here: prepare/send data ...
  led.indicateDataTransmission(); // visual feedback for transmission
}
```

If you split into multiple translation units, declare the instance `extern` in a header:
```cpp
// Globals.h
#include <ESP32C3MiniLED.h>
extern ESP32C3MiniLED led;

// main.ino
#include "Globals.h"
ESP32C3MiniLED led(RGB_LED_PIN);
```

## platformio.ini example
```ini
[env:lolin_c3_mini]
platform = espressif32
board = lolin_c3_mini
framework = arduino
lib_deps = adafruit/Adafruit NeoPixel
```

## Tips
- Adjust brightness in the constructor: `ESP32C3MiniLED led(RGB_LED_PIN, 1, 80);`
- If your RGB is not a NeoPixel (separate R/G/B GPIOs), do not use this library; adapt code for PWM pins.
- Keep only one global instance to avoid resource conflicts with the NeoPixel timing.

## License
MIT — see LICENSE file.