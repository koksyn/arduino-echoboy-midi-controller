#include "Pin.h"

Pin::Pin(uint8_t address, uint8_t mode) : address(address), mode(mode) {}

Pin::Pin(uint8_t address, uint8_t initialValue)
{
	this(address, OUTPUT);
    this->write(initialValue);
}

uint8_t Pin::getAddress()
{
	return this->address;
}

uint8_t Pin::getMode()
{
	return this->mode;
}

void Pin::requireInputMode()
{
	if(this->mode == OUTPUT)
	{
		throw logic_error("Cannot perform action, because Pin have OUTPUT mode.");
	}
}

void Pin::requireOutputMode()
{
	if(this->mode != OUTPUT)
	{
		throw logic_error("Cannot perform action, because Pin have not OUTPUT mode.");
	}
}