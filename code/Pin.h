#ifndef PIN_H
#define PIN_H

#include <Arduino.h>

class Pin {
private:
	uint8_t address;
	uint8_t mode;

protected:
	uint8_t getAddress();
	uint8_t getMode();

public:
	Pin(uint8_t address, uint8_t mode);

	virtual uint8_t read();
	virtual void write(uint8_t value);
	virtual void applyMode();
};

#endif