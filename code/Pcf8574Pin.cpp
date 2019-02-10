#include "Pcf8574Pin.h"

uint8_t Pcf8574Pin::read()
{
    return expander->digitalRead(getAddress());
}

void Pcf8574Pin::write(uint8_t value)
{
    expander->digitalWrite(getAddress(), value);
}

void Pcf8574Pin::applyMode()
{
    expander->pinMode(getAddress(), getMode());
}