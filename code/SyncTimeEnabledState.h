#ifndef SYNC_TIME_ENABLED_STATE_H
#define SYNC_TIME_ENABLED_STATE_H

#include "State.h"

class SyncTimeEnabledState : State {
private:
    static State* instance;
public:
    SyncTimeEnabledState(State* nextState) : State(nextState) {}
    void execute();
    static State* getInstance();
};

#endif
