#include "ArduinoDigitalPin.h"

#include <Arduino.h>

uint8_t ArduinoDigitalPin::read()
{
    return digitalRead(getAddress());
}

void ArduinoDigitalPin::write(uint8_t value)
{
    digitalWrite(getAddress(), value);
}

void ArduinoDigitalPin::applyMode()
{
    pinMode(getAddress(), getMode());
}

void ArduinoDigitalPin::attachInterrupt(void (*userFunc)(void), uint8_t interruptMode)
{
    ::attachInterrupt(digitalPinToInterrupt(getAddress()), userFunc, interruptMode);
}

void ArduinoDigitalPin::on()
{
    write(HIGH);
}

void ArduinoDigitalPin::off()
{
    write(LOW);
}