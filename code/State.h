#ifndef STATE_H
#define STATE_H

#include <Arduino.h>

class Machine;

typedef void(*Func)(void);

class State {
private:
    State* nextState;
    Func funcForExecute;
public:
    State(Func funcForExecute);
    void next(Machine* machine);
    void setNextState(State* nextState);
    void execute();
};

#endif
