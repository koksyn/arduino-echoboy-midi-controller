#include "DipMidi4ButtonHandler.h"

#include "MachineFactory.h"

void DipMidi4ButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("DipMidi");

    syncTime->nextState();
}