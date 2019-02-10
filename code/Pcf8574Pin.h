#ifndef PCF8574_PIN_H
#define PCF8574_PIN_H

#include <PCF8574.h>
#include "Pin.h"

class Pcf8574Pin : Pin {
private:
    PCF8574* expander;

public:
    Pcf8574Pin(uint8_t address, uint8_t mode, PCF8574* expander) : Pin(address, mode) {
        this->expander = expander;
    }

    void applyMode();
    uint8_t read();
    void write(uint8_t value);
    void attachInterrupt(void (*userFunc)(void), uint8_t interruptMode);
};

#endif
