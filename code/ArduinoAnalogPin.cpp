#include "ArduinoAnalogPin.h"

uint8_t ArduinoAnalogPin::read()
{
    return analogRead(getAddress());
}

void ArduinoAnalogPin::write(uint8_t value)
{
    // not allowed
}

void ArduinoAnalogPin::applyMode()
{
    pinMode(getAddress(), getMode());
}
