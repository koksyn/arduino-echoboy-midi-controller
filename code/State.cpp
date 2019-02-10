#include "State.h"

void State::next(Machine* machine)
{
    machine->setState(nextState);
}