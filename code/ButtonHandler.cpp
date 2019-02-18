#include "ButtonHandler.h"

#include "MachineFactory.h"
#include "PinFactory.h"

void ButtonHandler::handle(uint8_t code)
{
    int pinCode = (int) code;

    switch(pinCode) {
        // DIP MIDI
        case PIN_BUTTON_DIP_MIDI_1:
            break;
        case PIN_BUTTON_DIP_MIDI_2:
            break;
        case PIN_BUTTON_DIP_MIDI_3:
            break;
        case PIN_BUTTON_DIP_MIDI_4:
            break;

        // STYLE
        case PIN_BUTTON_STYLE_TAPE:
            break;
        case PIN_BUTTON_STYLE_ECHO:
            break;
        case PIN_BUTTON_STYLE_BBD:
            break;
        case PIN_BUTTON_STYLE_BIAS:
            break;
        case PIN_BUTTON_STYLE_CHORUS:
            break;
        case PIN_BUTTON_STYLE_ATMO:
            break;

        // MASTER
        case PIN_BUTTON_MIDI_ALL:
            break;
        case PIN_BUTTON_BYPASS:
            break;

        // MODE
        case PIN_BUTTON_MODE:
            break;

        // ECHO1 & ECHO2
        case PIN_BUTTON_ECHO_1:
            break;
        case PIN_BUTTON_ECHO_2:
            break;

        // LCD
        case PIN_BUTTON_SYNC_TIME:
            MachineFactory::get(MACHINE_SYNC_TIME)->nextState();
            break;

        case PIN_BUTTON_PRIME_NUMBERS:
            break;
    }
}