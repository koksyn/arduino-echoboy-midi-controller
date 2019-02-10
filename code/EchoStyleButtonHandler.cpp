#include "EchoStyleButtonHandler.h"

#include "MachineFactory.h"

void EchoStyleButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("EchoStyle");

    syncTime->nextState();
}