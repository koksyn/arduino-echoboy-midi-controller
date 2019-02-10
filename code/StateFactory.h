#ifndef STATE_FACTORY_H
#define STATE_FACTORY_H

#include <ArduinoSTL.h>
#include <map>
#include "State.h"

class StateFactory {
private:
    static std::map<String, State*> states;
    static bool notInitialized();
public:
    static void initialize();
    static State* get(String key);
};

#endif
