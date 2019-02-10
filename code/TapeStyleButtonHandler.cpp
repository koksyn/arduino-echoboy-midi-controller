#include "TapeStyleButtonHandler.h"

#include "MachineFactory.h"

void TapeStyleButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("TapeStyle");

    syncTime->nextState();
}