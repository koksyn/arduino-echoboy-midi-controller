#ifndef KNOB_MANAGER_H
#define KNOB_MANAGER_H

#include "PinFactory.h"
#include "MachineFactory.h"
#include "StateFactory.h"

// AMOUNT OF KNOBS
#define KNOBS 12

class KnobManager {
private:
    static uint8_t lastKnobValue[KNOBS];
public:
    static void initialize();
};

#endif
