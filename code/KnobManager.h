#ifndef KNOB_MANAGER_H
#define KNOB_MANAGER_H

#include "PinFactory.h"
#include "MachineFactory.h"
#include "StateFactory.h"
#include "LcdManager.h"

// https://www.arduino.cc/en/Tutorial/Smoothing
#define NUM_OF_READINGS 20

// AMOUNT OF KNOBS
#define KNOBS 13

class KnobManager {
private:
    static uint8_t knobReadings[KNOBS][NUM_OF_READINGS];
    static int knobReadIndex[KNOBS];
    static uint8_t knobReadTotal[KNOBS];
    static uint8_t knobReadAverage[KNOBS];

    static boolean readKnobAndSet(int knobPinNumber);
    static uint8_t readKnob(uint8_t knobPinNumber);
    static boolean knobValueExceededMargin(uint8_t knobPinNumber, uint8_t newValue, uint8_t marginalValue);
    static boolean valueNotBetween(uint8_t value, uint8_t x, uint8_t y);
public:
    static void initialize();
    static void updateAllKnobs();
};

#endif
