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
	void requireInputMode();
	void requireOutputMode();

public:
	Pin(uint8_t address, uint8_t mode);
	Pin(uint8_t address, uint8_t initialValue);

	virtual uint8_t read();
	virtual void write(uint8_t value);
};

#endif //PIN_H