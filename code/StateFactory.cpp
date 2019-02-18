#include "StateFactory.h"

#include "SyncTimeDisabledState.h"
#include "SyncTimeEnabledState.h"

State* StateFactory::states[STATES];

void StateFactory::initialize()
{
    // build
    states[STATE_SYNC_TIME_DISABLED] = (State*) new SyncTimeDisabledState();
    states[STATE_SYNC_TIME_ENABLED] = (State*) new SyncTimeEnabledState();

    // connect
    states[STATE_SYNC_TIME_DISABLED]->setNextState(states[STATE_SYNC_TIME_ENABLED]);
    states[STATE_SYNC_TIME_ENABLED]->setNextState(states[STATE_SYNC_TIME_DISABLED]);
}

State* StateFactory::get(int key)
{
    return states[key];
}
