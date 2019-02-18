#include "State.h"

#include "Machine.h"

State::State(Func funcForExecute)
{
    this->funcForExecute = funcForExecute;
}

void State::next(Machine* machine)
{
    machine->setState(nextState);
}

void State::setNextState(State* nextState)
{
    this->nextState = nextState;
}

void State::execute()
{
    funcForExecute();
}
