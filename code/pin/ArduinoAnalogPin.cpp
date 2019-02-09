#include "ArduinoAnalogPin.h"

uint8_t ArduinoAnalogPin::read()
{
    this->requireInputMode();

    return analogRead(this->getAddress());
}

void ArduinoAnalogPin::write(uint8_t value)
{
    this->requireOutputMode();

    analogWrite(this->getAddress(), value);
}