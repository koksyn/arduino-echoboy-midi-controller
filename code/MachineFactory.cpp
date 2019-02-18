#include "MachineFactory.h"

#include "SyncTimeMachine.h"

Machine* MachineFactory::machines[MACHINES];

void MachineFactory::initialize()
{
    machines[MACHINE_SYNC_TIME] = (Machine*) new SyncTimeMachine();
}

Machine* MachineFactory::get(int key)
{
    return machines[key];
}
