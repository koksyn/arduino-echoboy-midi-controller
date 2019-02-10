#include "Mcp3008Pin.h"

uint8_t Mcp3008Pin::read()
{
    return converter->readADC(getAddress());
}

void Mcp3008Pin::write(uint8_t value)
{
    // not allowed
}

void Mcp3008Pin::applyMode()
{

}

void Mcp3008Pin::attachInterrupt(void (*userFunc)(void), uint8_t interruptMode)
{
    // not implemented (or allowed)
}