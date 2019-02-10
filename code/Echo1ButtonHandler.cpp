#include "Echo1ButtonHandler.h"

#include "MachineFactory.h"

void Echo1ButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("Echo1");

    syncTime->nextState();
}