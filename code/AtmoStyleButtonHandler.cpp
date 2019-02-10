#include "AtmoStyleButtonHandler.h"

#include "MachineFactory.h"

void AtmoStyleButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("AtmoStyle");

    syncTime->nextState();
}