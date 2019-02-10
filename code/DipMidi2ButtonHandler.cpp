#include "DipMidi2ButtonHandler.h"

#include "MachineFactory.h"

void DipMidi2ButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("DipMidi");

    syncTime->nextState();
}