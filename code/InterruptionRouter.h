#ifndef INTERRUPTION_ROUTER_H
#define INTERRUPTION_ROUTER_H

extern volatile bool syncTimeButtonPressed;

class InterruptionRouter {
public:
    static void enableInterruptions();
};

#endif
