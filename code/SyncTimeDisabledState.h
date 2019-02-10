#ifndef SYNC_TIME_DISABLED_STATE_H
#define SYNC_TIME_DISABLED_STATE_H

#include "State.h"

class SyncTimeDisabledState : State 
{
private:
    static State* instance;
public:
    SyncTimeDisabledState(State* nextState) : State(nextState) {}
    void execute();
    static State* getInstance();
};

#endif
