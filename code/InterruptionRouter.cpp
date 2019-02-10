#include "InterruptionRouter.h"

#include "PinFactory.h"

void onExpanderInterrupt()
{
    Serial.println("I2C interrupt detected");

    PinFactory::getButtonExpander()
            ->checkForInterrupt();

    PinFactory::getButtonExpander2()
            ->checkForInterrupt();
}

// DIP MIDI
void handleDipMidi1Button() { dipMidi1ButtonPressed = true; }
void handleDipMidi2Button() { dipMidi2ButtonPressed = true; }
void handleDipMidi3Button() { dipMidi3ButtonPressed = true; }
void handleDipMidi4Button() { dipMidi4ButtonPressed = true; }

// STYLE
void handleTapeStyleButton() { tapeStyleButtonPressed = true; }
void handleEchoStyleButton() { echoStyleButtonPressed = true; }
void handleBbdStyleButton() { bbdStyleButtonPressed = true; }
void handleBiasStyleButton() { biasStyleButtonPressed = true; }
void handleChorusStyleButton() { chorusStyleButtonPressed = true; }
void handleAtmoStyleButton() { atmoStyleButtonPressed = true; }

// MASTER
void handleMidiAllButton() { midiAllButtonPressed = true; }
void handleBypassButton() { bypassButtonPressed = true; }

// MODE
void handleModeButton() { modeButtonPressed = true; }

// ECHO1 & ECHO2
void handleEcho1Button() { echo1ButtonPressed = true; }
void handleEcho2Button() { echo2ButtonPressed = true; }

// LCD
void handleSyncTimeButton() { syncTimeButtonPressed = true; }
void handlePrimeNumbersButton() { primeNumbersButtonPressed = true; }


void InterruptionRouter::enableInterruptions()
{
    // --- open Arduino PCF interrupt handling pin ---
    Pin* interruptForPCF = PinFactory::get("InterruptForPCF");
    interruptForPCF->write(HIGH);

    // --- enable interrupts for each dedicated PCF ---
    PinFactory::getButtonExpander()
            ->enableInterrupt(interruptForPCF->getAddress(), onExpanderInterrupt);

    PinFactory::getButtonExpander2()
            ->enableInterrupt(interruptForPCF->getAddress(), onExpanderInterrupt);

    // --- bind PCF pins to callbacks ---

    // ARDUINO Digital
    Pin* dipMidi1 = PinFactory::get("DipMidi1");
    dipMidi1->attachInterrupt(handleDipMidi1Button, CHANGE);

    // PCF 1 (INT) for BUTTONS
    Pin* dipMidi2 = PinFactory::get("DipMidi2");
    Pin* dipMidi3 = PinFactory::get("DipMidi3");
    Pin* dipMidi4 = PinFactory::get("DipMidi4");
    Pin* modeButton = PinFactory::get("ModeButton");
    Pin* echo1Button = PinFactory::get("Echo1Button");
    Pin* echo2Button = PinFactory::get("Echo2Button");
    Pin* syncTimeButton = PinFactory::get("SyncTimeButton");
    Pin* primeNumbersButton = PinFactory::get("PrimeNumbersButton");

    dipMidi2->attachInterrupt(handleDipMidi2Button, CHANGE);
    dipMidi3->attachInterrupt(handleDipMidi3Button, CHANGE);
    dipMidi4->attachInterrupt(handleDipMidi4Button, CHANGE);
    modeButton->attachInterrupt(handleModeButton, FALLING);
    echo1Button->attachInterrupt(handleEcho1Button, FALLING);
    echo2Button->attachInterrupt(handleEcho2Button, FALLING);
    syncTimeButton->attachInterrupt(handleSyncTimeButton, FALLING);
    primeNumbersButton->attachInterrupt(handlePrimeNumbersButton, FALLING);

    // PCF 2 (INT) for BUTTONS
    Pin* tapeStyleButton = PinFactory::get("TapeStyleButton");
    Pin* echoStyleButton = PinFactory::get("EchoStyleButton");
    Pin* bbdStyleButton = PinFactory::get("BbdStyleButton");
    Pin* biasStyleButton = PinFactory::get("BiasStyleButton");
    Pin* chorusStyleButton = PinFactory::get("ChorusStyleButton");
    Pin* atmoStyleButton = PinFactory::get("AtmoStyleButton");
    Pin* midiAllButton = PinFactory::get("MidiAllButton");
    Pin* bypassButton = PinFactory::get("BypassButton");

    tapeStyleButton->attachInterrupt(handleTapeStyleButton, FALLING);
    echoStyleButton->attachInterrupt(handleEchoStyleButton, FALLING);
    bbdStyleButton->attachInterrupt(handleBbdStyleButton, FALLING);
    biasStyleButton->attachInterrupt(handleBiasStyleButton, FALLING);
    chorusStyleButton->attachInterrupt(handleChorusStyleButton, FALLING);
    atmoStyleButton->attachInterrupt(handleAtmoStyleButton, FALLING);
    midiAllButton->attachInterrupt(handleMidiAllButton, FALLING);
    bypassButton->attachInterrupt(handleBypassButton, FALLING);
}