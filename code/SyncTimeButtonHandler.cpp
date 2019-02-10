#include "SyncTimeButtonHandler.h"

#include "MachineFactory.h"

void SyncTimeButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("SyncTime");

    syncTime->nextState();
}