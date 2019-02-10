#ifndef STATE_FACTORY_H
#define STATE_FACTORY_H

#include <ArduinoSTL.h>
#include <map>
#include "State.h"

class StateFactory {
private:
    static std::map<String, State*> states;
    static bool notInitialized();
    static void initialize();
public:
    static State* get(String key);
};

#endif
