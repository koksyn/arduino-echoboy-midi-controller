#ifndef Pin_h
#define Pin_h

#include <Arduino.h>

#define PIN_DEFAULT_VALUE LOW
// lub 0 (jesli bedzie bug compilacji)

class Pin {
private:
	uint8_t address;
	volatile uint8_t value;

public:
	Pin(uint8_t address);
	Pin(uint8_t address, uint8_t initialValue);

	virtual uint8_t read();
	virtual void write(uint8_t value);
};

#endif