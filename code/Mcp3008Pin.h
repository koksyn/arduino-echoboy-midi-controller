#ifndef MCP3008_PIN_H
#define MCP3008_PIN_H

#include <Adafruit_MCP3008.h>
#include "Pin.h"

class Mcp3008Pin : Pin {
private:
    Adafruit_MCP3008* converter;

public:
    Mcp3008Pin(uint8_t address, uint8_t mode, Adafruit_MCP3008* converter) : Pin(address, mode) {
        this->converter = converter;
        applyMode();
    }

    void applyMode();
    short read();
    void write(uint8_t value);
    void attachInterrupt(void (*userFunc)(void), uint8_t interruptMode);
};

#endif
