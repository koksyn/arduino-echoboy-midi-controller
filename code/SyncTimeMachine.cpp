#include "SyncTimeMachine.h"

void SyncTimeMachine::setDefaultState()
{
    setState(SyncTimeDisabledState::getInstance());
}