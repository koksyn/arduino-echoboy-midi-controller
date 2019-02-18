#include "MachineFactory.h"

#include "StateFactory.h"

Machine* MachineFactory::machines[MACHINES];

void MachineFactory::initialize()
{
    machines[MACHINE_SYNC_TIME] = new Machine(StateFactory::get(STATE_SYNC_TIME_DISABLED));
}

Machine* MachineFactory::get(int key)
{
    return machines[key];
}
