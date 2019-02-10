#include "State.h"

#include "Machine.h"

void State::next(Machine* machine)
{
    machine->setState(nextState);
}

void State::setNextState(State* nextState)
{
    this->nextState = nextState;
}
