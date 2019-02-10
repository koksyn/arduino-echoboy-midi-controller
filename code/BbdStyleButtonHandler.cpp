#include "BbdStyleButtonHandler.h"

#include "MachineFactory.h"

void BbdStyleButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("BbdStyle");

    syncTime->nextState();
}