#ifndef ARDUINO_ANALOG_PIN_H
#define ARDUINO_ANALOG_PIN_H

#include "Pin.h"

class ArduinoAnalogPin : Pin {
public:
  ArduinoAnalogPin(uint8_t address, uint8_t mode) : Pin(address, mode) { }
  uint8_t read();
  void write(uint8_t value);  
};

#endif
