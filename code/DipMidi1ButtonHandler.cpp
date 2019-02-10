#include "DipMidi1ButtonHandler.h"

#include "MachineFactory.h"

void DipMidi1ButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("DipMidi");

    syncTime->nextState();
}