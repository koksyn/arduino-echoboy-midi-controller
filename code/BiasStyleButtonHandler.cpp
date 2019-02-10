#include "BiasStyleButtonHandler.h"

#include "MachineFactory.h"

void BiasStyleButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("BiasStyle");

    syncTime->nextState();
}