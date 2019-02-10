#ifndef MACHINE_FACTORY_H
#define MACHINE_FACTORY_H

#include <ArduinoSTL.h>
#include <map>
#include "Machine.h"

class MachineFactory {
private:
    static std::map<String, Machine*> machines;
    static bool notInitialized();
    static void initialize();
public:
    static Machine* get(String key);
};

#endif
