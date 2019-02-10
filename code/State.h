#ifndef STATE_H
#define STATE_H

#include "Machine.h"

class State {
private:
    State* nextState;
public:
    State(State* nextState) : nextState(nextState) {}
    void next(Machine* machine);

    virtual void execute();
};

#endif
