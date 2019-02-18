#ifndef INTERRUPTION_ROUTER_H
#define INTERRUPTION_ROUTER_H

#include <Arduino.h>

extern volatile uint8_t buttonPressed;

class InterruptionRouter {
public:
    static void enableInterruptions();
};

#endif
