#include "ArduinoDigitalPin.h"

uint8_t ArduinoDigitalPin::read()
{
    return digitalRead(this->getAddress());
}

void ArduinoDigitalPin::write(uint8_t value)
{
    digitalWrite(this->getAddress(), value);
}

void ArduinoDigitalPin::applyMode()
{
    pinMode(getAddress(), getMode());
}