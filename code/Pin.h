#ifndef PIN_H
#define PIN_H

#include <Arduino.h>

class Pin {
private:
	uint8_t address;
	uint8_t mode;

protected:
	uint8_t getMode();

public:
	Pin(uint8_t address, uint8_t mode);

	uint8_t getAddress();

	virtual uint8_t read();
	virtual void write(uint8_t value);
	virtual void applyMode();
	virtual void attachInterrupt(void (*userFunc)(void), uint8_t interruptMode);
};

#endif