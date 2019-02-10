#include "PrimeNumbersButtonHandler.h"

#include "MachineFactory.h"

void PrimeNumbersButtonHandler::handle()
{
    Machine* syncTime = MachineFactory::get("PrimeNumbers");

    syncTime->nextState();
}