#ifndef STATE_FACTORY_H
#define STATE_FACTORY_H

#include "State.h"

#define STATE_SYNC_TIME_DISABLED 0
#define STATE_SYNC_TIME_ENABLED 1

// AMOUNT OF MACHINES
#define STATES 1

class StateFactory {
private:
    static State* states[STATES];
public:
    static void initialize();
    static State* get(int key);
};

#endif
