#include "Machine.h"

Machine::Machine(State* initialState)
{
	this->currentState = nullptr;
    this->initialState = initialState;
	applyInitialState();
}

void Machine::setState(State *state)
{
	if(!equalsState(state))
	{
		currentState = state;
	}
}

void Machine::nextState()
{
	currentState->next(this);
	executeCurrentState();
}

void Machine::applyInitialState()
{
	if(!equalsState(this->initialState))
	{
		setState(this->initialState);
		executeCurrentState();
	}
}

void Machine::executeCurrentState()
{
	currentState->execute();
}

bool Machine::equalsState(State* state)
{
	return state == currentState;
}