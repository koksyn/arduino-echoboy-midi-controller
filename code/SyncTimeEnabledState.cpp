#include "SyncTimeEnabledState.h"
#include "SyncTimeDisabledState.h"

void SyncTimeEnabledState::execute()
{
    Serial.println("ENABLED");
}

State* SyncTimeEnabledState::getInstance()
{
    if(instance == nullptr)
    {
        instance = new SyncTimeEnabledState(nullptr);  // avoiding Cycles

        State* nextState = SyncTimeDisabledState::getInstance();
        instance->setNextState(nextState);
    }

    return instance;
}
