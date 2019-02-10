#include "MachineFactory.h"

#include "SyncTimeMachine.h"

std::map<String, Machine*> MachineFactory::machines;

bool MachineFactory::notInitialized()
{
    return machines.empty();
}

void MachineFactory::initialize()
{
    // build
    Machine* syncTime = (Machine*) new SyncTimeMachine();

    // insert
    machines.insert(std::pair<String, Machine*>("SyncTime", syncTime));
}

Machine* MachineFactory::get(String key)
{
    if(notInitialized()) {
        initialize();
    }

    auto search = machines.find(key);

    if(search == machines.end()) {
        // Very useful debug
        Serial.print("Machine not found! Name: ");
        Serial.println(key);
        delay(500);

        return nullptr;
    }

    return machines[key];
}
