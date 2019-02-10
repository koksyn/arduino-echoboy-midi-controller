#ifndef ARDUINO_DIGITAL_PIN_H
#define ARDUINO_DIGITAL_PIN_H

#include "Pin.h"

class ArduinoDigitalPin : Pin {
public:
    ArduinoDigitalPin(uint8_t address, uint8_t mode) : Pin(address, mode) { applyMode(); }

    void applyMode();
    uint8_t read();
    void write(uint8_t value);  
};

#endif
