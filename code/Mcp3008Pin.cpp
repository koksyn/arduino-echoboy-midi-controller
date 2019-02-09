#include "Mcp3008Pin.h"

uint8_t Mcp3008Pin::read()
{
    return converter->readADC(this->getAddress());
}

void Mcp3008Pin::write(uint8_t value)
{
    // not allowed
}

void Mcp3008Pin::applyMode()
{
    converter->begin();
}
