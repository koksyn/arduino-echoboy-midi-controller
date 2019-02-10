#include "Echo2ButtonHandler.h"

#include "MachineFactory.h"

void Echo2ButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("Echo2");

    syncTime->nextState();
}