#include "MidiAllButtonHandler.h"

#include "MachineFactory.h"

void MidiAllButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("MidiAll");

    syncTime->nextState();
}