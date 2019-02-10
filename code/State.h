#ifndef STATE_H
#define STATE_H

#include <Arduino.h>

class Machine;

class State {
private:
    State* nextState;
public:
    void next(Machine* machine);
    void setNextState(State* nextState);

    virtual void execute();
};

#endif
