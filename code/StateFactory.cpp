#include "StateFactory.h"

#include "SyncTimeDisabledState.h"
#include "SyncTimeEnabledState.h"

std::map<String, State*> StateFactory::states;

bool StateFactory::notInitialized()
{
    return states.empty();
}

void StateFactory::initialize()
{
    /**
     * --- SyncTime states ---
     */
    // build
    State* syncTimeDisabled = (State*) new SyncTimeDisabledState();
    State* syncTimeEnabled = (State*) new SyncTimeEnabledState();

    // connect
    syncTimeDisabled->setNextState(syncTimeEnabled);
    syncTimeEnabled->setNextState(syncTimeDisabled);

    // insert
    states.insert(std::pair<String, State*>("SyncTimeDisabled", syncTimeDisabled));
    states.insert(std::pair<String, State*>("SyncTimeEnabled", syncTimeEnabled));

    /**
     * ---  states ---
     */
    // build
    // connect
    // insert
}

State* StateFactory::get(String key)
{
    if(notInitialized()) {
        initialize();
    }

    auto search = states.find(key);

    if(search == states.end()) {
        // Very useful debug
        Serial.print("State not found! Name: ");
        Serial.println(key);
        delay(500);

        return nullptr;
    }

    return states[key];
}
