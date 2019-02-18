#include "StateFactory.h"

State* StateFactory::states[STATES];

void StateFactory::initialize()
{
    // build
    states[STATE_SYNC_TIME_DISABLED] = new State([&]() {
        Serial.println("Disabled");
    });

    states[STATE_SYNC_TIME_ENABLED] = new State([&]() {
        Serial.println("Enabled");
    });

    // connect
    states[STATE_SYNC_TIME_DISABLED]->setNextState(states[STATE_SYNC_TIME_ENABLED]);
    states[STATE_SYNC_TIME_ENABLED]->setNextState(states[STATE_SYNC_TIME_DISABLED]);
}

State* StateFactory::get(int key)
{
    return states[key];
}
