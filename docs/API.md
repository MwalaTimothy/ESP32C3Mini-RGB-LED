# API Documentation

## Class: ESP32C3MiniLED

### Constructor

```cpp
ESP32C3MiniLED(uint8_t pin, uint8_t numPixels = 1, uint8_t brightness = 50)
```

Creates a new ESP32C3MiniLED instance.

#### Parameters:
- `pin`: The GPIO pin number connected to the RGB LED
- `numPixels`: (Optional) Number of RGB LEDs in the chain. Default is 1.
- `brightness`: (Optional) Initial brightness level (0-255). Default is 50.

### Methods

#### begin()

```cpp
void begin()
```

Initializes the RGB LED and runs the startup sequence.
- Sets the configured brightness
- Clears any previous state
- Runs the startup color sequence

#### indicateDataTransmission()

```cpp
void indicateDataTransmission()
```

Provides visual feedback for data transmission events.
- Shows a short purple blink
- Duration: 300ms (200ms on, 100ms off)
- Useful for indicating network activity, file operations, etc.

#### indicateStartupSequence()

```cpp
void indicateStartupSequence()
```

Runs the standard startup color sequence:
1. Red (400ms)
2. Blue (400ms)
3. Orange (400ms)
4. Violet (400ms)
5. Off

### Private Methods

#### setColor()

```cpp
void setColor(uint8_t r, uint8_t g, uint8_t b, uint16_t ms = 0)
```

Internal method to set the RGB LED color.
- `r`, `g`, `b`: Color values (0-255)
- `ms`: Optional delay after setting color

## Hardware Compatibility

### Tested Boards

| Board | Default Pin | Notes |
|-------|------------|-------|
| ESP32-C3 Mini | 8 | Built-in RGB LED |
| LOLIN C3 Mini | 7 | Built-in RGB LED |

### Pin Selection

When selecting a pin for external RGB LEDs:
- Use a pin that supports digital output
- Avoid pins used for system functions
- Consider voltage and current requirements