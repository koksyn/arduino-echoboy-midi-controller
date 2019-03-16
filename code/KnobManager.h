#ifndef KNOB_MANAGER_H
#define KNOB_MANAGER_H

// https://github.com/dxinteractive/ResponsiveAnalogRead
#include <ResponsiveAnalogRead.h>

#include "PinFactory.h"
#include "MachineFactory.h"
#include "StateFactory.h"
#include "LcdManager.h"
#include "MidiProxy.h"

// AMOUNT OF KNOBS
#define KNOBS 13

class KnobManager {
private:
    static ResponsiveAnalogRead* reading[KNOBS];

    static boolean readKnobAndSet(int knobPinNumber);
    static int readKnob(uint8_t knobPinNumber);
    static void sendKnobValueAsMidiCC(int knobPinNumber);
public:
    static void initialize();
    static void updateAllKnobs();
};

#endif
