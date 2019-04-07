#ifndef ARDUINO_DIGITAL_PIN_H
#define ARDUINO_DIGITAL_PIN_H

#include "Pin.h"

class ArduinoDigitalPin : Pin {
public:
    ArduinoDigitalPin(uint8_t address, uint8_t mode) : Pin(address, mode) { applyMode(); }

    void applyMode();
    short read();
    void write(uint8_t value);
    void attachInterrupt(void (*userFunc)(void), uint8_t interruptMode);
};

#endif
