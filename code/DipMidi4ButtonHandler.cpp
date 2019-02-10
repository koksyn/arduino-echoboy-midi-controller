#include "DipMidi4ButtonHandler.h"

void DipMidi4ButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("DipMidi");

    syncTime->nextState();
}