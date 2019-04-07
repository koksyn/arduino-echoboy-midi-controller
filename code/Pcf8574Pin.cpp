#include "Pcf8574Pin.h"

short Pcf8574Pin::read()
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

void Pcf8574Pin::attachInterrupt(void (*userFunc)(void), uint8_t interruptMode)
{
    expander->attachInterrupt(getAddress(), userFunc, interruptMode);
}
