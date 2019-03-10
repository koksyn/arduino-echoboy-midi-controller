#ifndef ARDUINO_ANALOG_PIN_H
#define ARDUINO_ANALOG_PIN_H

#include "Pin.h"

class ArduinoAnalogPin : Pin {
public:
    ArduinoAnalogPin(uint8_t address, uint8_t mode) : Pin(address, mode) { applyMode(); }

    void applyMode();
    uint8_t read();
    void write(uint8_t value);
    void attachInterrupt(void (*userFunc)(void), uint8_t interruptMode);
    void on();
    void off();
};

#endif
