#include "ChorusStyleButtonHandler.h"

#include "MachineFactory.h"

void ChorusStyleButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("ChorusStyle");

    syncTime->nextState();
}