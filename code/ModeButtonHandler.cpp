#include "ModeButtonHandler.h"

#include "MachineFactory.h"

void ModeButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("Mode");

    syncTime->nextState();
}