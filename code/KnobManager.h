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

// used when User have not SYNC mode enabled
// or when User does not change Echo Time after Synchronization
#define EMPTY_SYNC -1

class KnobManager {
private:
    static ResponsiveAnalogRead* reading[KNOBS];

    static boolean readKnobAndSet(int knobPinNumber);
    static int readKnob(uint8_t knobPinNumber);
public:
    static void initialize();
    static void updateAllKnobs();
    static void forceAllKnobsToSendMIDI();
};

#endif
