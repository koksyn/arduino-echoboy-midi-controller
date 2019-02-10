#include "BypassButtonHandler.h"

#include "MachineFactory.h"

void BypassButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("Bypass");

    syncTime->nextState();
}