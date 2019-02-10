#include "State.h"

void State::next(Machine* machine)
{
    machine->setState(nextState);
}

State* State::getInstance()
{
    return nullptr; // it should be implemented in child classes, but C++ does not allow us to create "static virtual" methods
}

void State::setNextState(State* nextState)
{
    this->nextState = nextState;
}