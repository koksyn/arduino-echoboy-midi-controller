#include "DipMidi3ButtonHandler.h"

#include "MachineFactory.h"

void DipMidi3ButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("DipMidi");

    syncTime->nextState();
}