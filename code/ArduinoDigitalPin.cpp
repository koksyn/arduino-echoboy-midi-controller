#include "ArduinoDigitalPin.h"

uint8_t ArduinoDigitalPin::read()
{
    return digitalRead(getAddress());
}

void ArduinoDigitalPin::write(uint8_t value)
{
    digitalWrite(getAddress(), value);
}

void ArduinoDigitalPin::applyMode()
{
    pinMode(getAddress(), getMode());
}