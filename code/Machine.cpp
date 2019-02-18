#include "Machine.h"

Machine::Machine(State* initialState)
{
    setState(initialState);
	executeCurrentState();
}

void Machine::setState(State *state)
{
	currentState = state;
}

void Machine::nextState()
{
	currentState->next(this);
	executeCurrentState();
}

void Machine::executeCurrentState()
{
	currentState->execute();
}