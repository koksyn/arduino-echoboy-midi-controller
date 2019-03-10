#include "Pin.h"

Pin::Pin(uint8_t address, uint8_t mode) : address(address), mode(mode) {}

uint8_t Pin::getAddress()
{
	return address;
}

uint8_t Pin::getMode()
{
	return mode;
}