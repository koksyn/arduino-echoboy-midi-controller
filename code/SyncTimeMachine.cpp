#include "SyncTimeMachine.h"

#include "StateFactory.h"

SyncTimeMachine::SyncTimeMachine()
{
    setDefaultState();
    executeCurrentState();
}

void SyncTimeMachine::setDefaultState()
{
    setState(StateFactory::get("SyncTimeDisabledState"));
}