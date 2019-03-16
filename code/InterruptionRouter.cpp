#include "InterruptionRouter.h"

#include "PinFactory.h"

void onExpanderInterrupt()
{
    PinFactory::getButtonExpander()
            ->checkForInterrupt();
}

void onExpander2Interrupt()
{
    PinFactory::getButtonExpander2()
            ->checkForInterrupt();
}

void InterruptionRouter::enableInterruptions()
{
    // --- open Arduino PCF interrupt handling pin ---
    Pin* interruptForPCF = PinFactory::get(PIN_INT_FROM_PCF);
    interruptForPCF->write(HIGH);

    Pin* interruptForPCF2 = PinFactory::get(PIN_INT_FROM_PCF_2);
    interruptForPCF2->write(HIGH);

    // --- enable interrupts for each dedicated PCF ---
    attachInterrupt(digitalPinToInterrupt(interruptForPCF->getAddress()), onExpanderInterrupt, FALLING);
    attachInterrupt(digitalPinToInterrupt(interruptForPCF2->getAddress()), onExpander2Interrupt, FALLING);

    // --- bind PCF pins to callbacks (using lambdas) ---

    // ARDUINO Digital
    PinFactory::get(PIN_BUTTON_DIP_MIDI_1)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_DIP_MIDI_1;
    }, CHANGE);

    // PCF 1 (INT) for BUTTONS
    PinFactory::get(PIN_BUTTON_DIP_MIDI_2)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_DIP_MIDI_2;
    }, CHANGE);

    PinFactory::get(PIN_BUTTON_DIP_MIDI_3)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_DIP_MIDI_3;
    }, CHANGE);

    PinFactory::get(PIN_BUTTON_DIP_MIDI_4)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_DIP_MIDI_4;
    }, CHANGE);

    PinFactory::get(PIN_BUTTON_MODE)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_MODE;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_ECHO_1)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_ECHO_1;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_ECHO_2)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_ECHO_2;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_SYNC_TIME)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_SYNC_TIME;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_PRIME_NUMBERS)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_PRIME_NUMBERS;
    }, FALLING);

    // PCF 2 (INT) for BUTTONS
    PinFactory::get(PIN_BUTTON_STYLE_TAPE)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_STYLE_TAPE;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_STYLE_ECHO)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_STYLE_ECHO;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_STYLE_BBD)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_STYLE_BBD;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_STYLE_BIAS)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_STYLE_BIAS;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_STYLE_CHORUS)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_STYLE_CHORUS;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_STYLE_ATMO)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_STYLE_ATMO;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_MIDI_ALL)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_MIDI_ALL;
    }, FALLING);

    PinFactory::get(PIN_BUTTON_BYPASS)->attachInterrupt([&]() {
        buttonPressed = PIN_BUTTON_BYPASS;
    }, FALLING);
}
