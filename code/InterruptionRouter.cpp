#include "InterruptionRouter.h"

#include "PinFactory.h"

void onExpanderInterrupt()
{
    Serial.println("Przerwanie na szynie I2C");

    PinFactory::getButtonExpander()
            ->checkForInterrupt();

    PinFactory::getButtonExpander2()
            ->checkForInterrupt();
}

void handleSyncTimeButton() { syncTimeButtonPressed = true; }

void handlePrimeNumbersButton() { Serial.println("handlePrimeNumbersButton"); }

void InterruptionRouter::enableInterruptions()
{
    // open Arduino PCF interrupt handling pin
    Pin* interruptForPCF = PinFactory::get("InterruptForPCF");
    interruptForPCF->write(HIGH);

    // enable interrupts for each PCF
    PinFactory::getButtonExpander()
            ->enableInterrupt(interruptForPCF->getAddress(), onExpanderInterrupt);

    PinFactory::getButtonExpander2()
            ->enableInterrupt(interruptForPCF->getAddress(), onExpanderInterrupt);

    // attach INT on 5 pin
    PinFactory::getButtonExpander()
            ->attachInterrupt(4, handleSyncTimeButton, FALLING); // tu adres buttonu odpowiedniego z fabryki

    // 6 pin
    PinFactory::getButtonExpander2()
            ->attachInterrupt(4, handlePrimeNumbersButton, FALLING);  // tu adres buttonu odpowiedniego z fabryki
}