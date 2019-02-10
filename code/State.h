#ifndef STATE_H
#define STATE_H


#include <Arduino.h>

class Machine;
#include "Machine.h"

class State {
private:
    State* nextState;
public:
    State(State* nextState) : nextState(nextState) {}
    void next(Machine* machine);
    void setNextState(State* nextState);

    virtual void execute();
    static State* getInstance();
};

#endif
