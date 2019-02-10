#include "SyncTimeMachine.h"
#include "SyncTimeDisabledState.h"

void SyncTimeMachine::setDefaultState()
{
    setState(SyncTimeDisabledState::getInstance());
}