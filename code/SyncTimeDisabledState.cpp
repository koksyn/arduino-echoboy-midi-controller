#include "SyncTimeDisabledState.h"
#include "SyncTimeEnabledState.h"

void SyncTimeDisabledState::execute()
{
    Serial.println("DISABLED");
}

State* SyncTimeDisabledState::getInstance()
{
    if(instance == nullptr)
    {
        instance = new SyncTimeDisabledState(nullptr); // avoiding Cycles

        State* nextState = SyncTimeEnabledState::getInstance();
        instance->setNextState(nextState);
    }

    return instance;
}