#include "Mcp3008Pin.h"

int Mcp3008Pin::read()
{
    return converter->readADC(getAddress());
}

void Mcp3008Pin::write(uint8_t value)
{
    // not allowed
}

void Mcp3008Pin::applyMode()
{
    // not handled
}

void Mcp3008Pin::attachInterrupt(void (*userFunc)(void), uint8_t interruptMode)
{
    // not handled
}
