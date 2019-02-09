#include "ArduinoDigitalPin.h"

uint8_t ArduinoDigitalPin::read()
{
    this->requireInputMode();

    return digitalRead(this->getAddress());
}

void ArduinoDigitalPin::write(uint8_t value)
{
    this->requireOutputMode();

    digitalWrite(this->getAddress(), value);
}