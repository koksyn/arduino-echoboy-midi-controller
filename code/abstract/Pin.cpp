#include "Pin.h"

Pin::Pin(uint8_t address)
{
	this->address = address;
	this->value = PIN_DEFAULT_VALUE;
}

Pin::Pin(uint8_t address, uint8_t initialValue)
{
	this->address = address;
	this->value = initialValue;
}