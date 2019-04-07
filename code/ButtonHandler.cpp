#include "ButtonHandler.h"

#include "MachineFactory.h"
#include "StateFactory.h"
#include "PinFactory.h"
#include "KnobManager.h"

short pinCode = 0;

void ButtonHandler::handle(uint8_t code)
{
    pinCode = (short) code;

    switch(pinCode) {
        // STYLE
        case PIN_BUTTON_STYLE_TAPE:
            // was disabled
            if(MachineFactory::get(MACHINE_STYLE_TAPE)->equalsState(StateFactory::get(STATE_STYLE_TAPE_DISABLED))) {
                // disable all other Style machines
                MachineFactory::get(MACHINE_STYLE_ECHO)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BBD)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BIAS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_CHORUS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_ATMO)->applyInitialState();
                // enable choosed
                MachineFactory::get(MACHINE_STYLE_TAPE)->applyInitialState();
            }
            // was enabled
            else {
                MachineFactory::get(MACHINE_STYLE_TAPE)->nextState();
            }
            break;
        case PIN_BUTTON_STYLE_ECHO:
            // was disabled
            if(MachineFactory::get(MACHINE_STYLE_ECHO)->equalsState(StateFactory::get(STATE_STYLE_ECHO_DISABLED))) {
                // disable all other Style machines
                MachineFactory::get(MACHINE_STYLE_TAPE)->setState(StateFactory::get(STATE_STYLE_TAPE_DISABLED));
                MachineFactory::get(MACHINE_STYLE_TAPE)->executeCurrentState();

                MachineFactory::get(MACHINE_STYLE_BBD)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BIAS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_CHORUS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_ATMO)->applyInitialState();
                // enable choosed
                MachineFactory::get(MACHINE_STYLE_ECHO)->setState(StateFactory::get(STATE_STYLE_ECHO_PLEX));
                MachineFactory::get(MACHINE_STYLE_ECHO)->executeCurrentState();
            }
            // was enabled
            else {
                MachineFactory::get(MACHINE_STYLE_ECHO)->nextState();
            }
            break;
        case PIN_BUTTON_STYLE_BBD:
            // was disabled
            if(MachineFactory::get(MACHINE_STYLE_BBD)->equalsState(StateFactory::get(STATE_STYLE_BBD_DISABLED))) {
                // disable all other Style machines
                MachineFactory::get(MACHINE_STYLE_TAPE)->setState(StateFactory::get(STATE_STYLE_TAPE_DISABLED));
                MachineFactory::get(MACHINE_STYLE_TAPE)->executeCurrentState();

                MachineFactory::get(MACHINE_STYLE_ECHO)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BIAS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_CHORUS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_ATMO)->applyInitialState();
                // enable choosed
                MachineFactory::get(MACHINE_STYLE_BBD)->setState(StateFactory::get(STATE_STYLE_BBD_MEMORY_MAN));
                MachineFactory::get(MACHINE_STYLE_BBD)->executeCurrentState();
            }
            // was enabled
            else {
                MachineFactory::get(MACHINE_STYLE_BBD)->nextState();
            }
            break;
        case PIN_BUTTON_STYLE_BIAS:
            // was disabled
            if(MachineFactory::get(MACHINE_STYLE_BIAS)->equalsState(StateFactory::get(STATE_STYLE_BIAS_DISABLED))) {
                // disable all other Style machines
                MachineFactory::get(MACHINE_STYLE_TAPE)->setState(StateFactory::get(STATE_STYLE_TAPE_DISABLED));
                MachineFactory::get(MACHINE_STYLE_TAPE)->executeCurrentState();

                MachineFactory::get(MACHINE_STYLE_ECHO)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BBD)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_CHORUS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_ATMO)->applyInitialState();
                // enable choosed
                MachineFactory::get(MACHINE_STYLE_BIAS)->setState(StateFactory::get(STATE_STYLE_BIAS_TRANSMITTER));
                MachineFactory::get(MACHINE_STYLE_BIAS)->executeCurrentState();
            }
            // was enabled
            else {
                MachineFactory::get(MACHINE_STYLE_BIAS)->nextState();
            }
            break;
        case PIN_BUTTON_STYLE_CHORUS:
            // was disabled
            if(MachineFactory::get(MACHINE_STYLE_CHORUS)->equalsState(StateFactory::get(STATE_STYLE_CHORUS_DISABLED))) {
                // disable all other Style machines
                MachineFactory::get(MACHINE_STYLE_TAPE)->setState(StateFactory::get(STATE_STYLE_TAPE_DISABLED));
                MachineFactory::get(MACHINE_STYLE_TAPE)->executeCurrentState();

                MachineFactory::get(MACHINE_STYLE_ECHO)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BBD)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BIAS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_ATMO)->applyInitialState();
                // enable choosed
                MachineFactory::get(MACHINE_STYLE_CHORUS)->setState(StateFactory::get(STATE_STYLE_CHORUS_CE_1));
                MachineFactory::get(MACHINE_STYLE_CHORUS)->executeCurrentState();
            }
            // was enabled
            else {
                MachineFactory::get(MACHINE_STYLE_CHORUS)->nextState();
            }
            break;
        case PIN_BUTTON_STYLE_ATMO:
            // was disabled
            if(MachineFactory::get(MACHINE_STYLE_ATMO)->equalsState(StateFactory::get(STATE_STYLE_ATMO_DISABLED))) {
                // disable all other Style machines
                MachineFactory::get(MACHINE_STYLE_TAPE)->setState(StateFactory::get(STATE_STYLE_TAPE_DISABLED));
                MachineFactory::get(MACHINE_STYLE_TAPE)->executeCurrentState();

                MachineFactory::get(MACHINE_STYLE_ECHO)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BBD)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_BIAS)->applyInitialState();
                MachineFactory::get(MACHINE_STYLE_CHORUS)->applyInitialState();
                // enable choosed
                MachineFactory::get(MACHINE_STYLE_ATMO)->setState(StateFactory::get(STATE_STYLE_ATMO_AMBIENT));
                MachineFactory::get(MACHINE_STYLE_ATMO)->executeCurrentState();
            }
            // was enabled
            else {
                MachineFactory::get(MACHINE_STYLE_ATMO)->nextState();
            }
            break;

        // MASTER
        case PIN_BUTTON_MIDI_ALL:
            // LED on
            PinFactory::get(PIN_LED_MIDI_ALL)->write(HIGH);

            // execute all machines
            for(byte i=0; i<MACHINES; i++) {
                MachineFactory::get(i)->executeCurrentState();
            }
            // execute all knobs
            KnobManager::forceAllKnobsToSendMIDI();

            // delay + LED off
            delay(100);
            PinFactory::get(PIN_LED_MIDI_ALL)->write(LOW);
            break;
        case PIN_BUTTON_BYPASS:
            MachineFactory::get(MACHINE_BYPASS)->nextState();
            break;

        // MODE
        case PIN_BUTTON_MODE:
            MachineFactory::get(MACHINE_MODE)->nextState();

            // when user just change MODE to RHYTM or SINGLE
            if(MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_RHYTM)) ||
               MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_SINGLE))) {
                if((MachineFactory::get(MACHINE_ECHO_1)->equalsState(StateFactory::get(STATE_ECHO_1_NOTE)) &&
                    MachineFactory::get(MACHINE_ECHO_2)->equalsState(StateFactory::get(STATE_ECHO_2_TIME)))
                   ||
                   (MachineFactory::get(MACHINE_ECHO_1)->equalsState(StateFactory::get(STATE_ECHO_1_TIME)) &&
                    MachineFactory::get(MACHINE_ECHO_2)->equalsState(StateFactory::get(STATE_ECHO_2_NOTE))))
                {
                    // synchronize also TIME DIVISION ECHO1-ECHO2
                    MachineFactory::get(MACHINE_ECHO_2)->nextState();
                }
            }

            break;

        // ECHO1 & ECHO2
        case PIN_BUTTON_ECHO_1:
            MachineFactory::get(MACHINE_ECHO_1)->nextState();

            // when user is in RHYTM or SINGLE MODE -> OR -> IS IN SYNC
            if(MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_RHYTM)) ||
               MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_SINGLE)) ||
               MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
                if((MachineFactory::get(MACHINE_ECHO_1)->equalsState(StateFactory::get(STATE_ECHO_1_NOTE)) &&
                    MachineFactory::get(MACHINE_ECHO_2)->equalsState(StateFactory::get(STATE_ECHO_2_TIME)))
                   ||
                   (MachineFactory::get(MACHINE_ECHO_1)->equalsState(StateFactory::get(STATE_ECHO_1_TIME)) &&
                    MachineFactory::get(MACHINE_ECHO_2)->equalsState(StateFactory::get(STATE_ECHO_2_NOTE))))
                {
                    // synchronize also TIME DIVISION ECHO1-ECHO2
                    MachineFactory::get(MACHINE_ECHO_2)->nextState();
                }
            }

            break;
        case PIN_BUTTON_ECHO_2:
            MachineFactory::get(MACHINE_ECHO_2)->nextState();

            // when user is in RHYTM or SINGLE MODE -> OR -> IS IN SYNC
            if(MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_RHYTM)) ||
               MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_SINGLE)) ||
               MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
                if((MachineFactory::get(MACHINE_ECHO_2)->equalsState(StateFactory::get(STATE_ECHO_2_NOTE)) &&
                    MachineFactory::get(MACHINE_ECHO_1)->equalsState(StateFactory::get(STATE_ECHO_1_TIME)))
                   ||
                   (MachineFactory::get(MACHINE_ECHO_2)->equalsState(StateFactory::get(STATE_ECHO_2_TIME)) &&
                    MachineFactory::get(MACHINE_ECHO_1)->equalsState(StateFactory::get(STATE_ECHO_1_NOTE))))
                {
                    // synchronize also TIME DIVISION ECHO1-ECHO2
                    MachineFactory::get(MACHINE_ECHO_1)->nextState();
                }
            }
            break;

        // LCD
        case PIN_BUTTON_SYNC_TIME:
            MachineFactory::get(MACHINE_SYNC_TIME)->nextState();

            // when user just enabled SYNC
            if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
                if((MachineFactory::get(MACHINE_ECHO_1)->equalsState(StateFactory::get(STATE_ECHO_1_NOTE)) &&
                   MachineFactory::get(MACHINE_ECHO_2)->equalsState(StateFactory::get(STATE_ECHO_2_TIME)))
                    ||
                  (MachineFactory::get(MACHINE_ECHO_1)->equalsState(StateFactory::get(STATE_ECHO_1_TIME)) &&
                   MachineFactory::get(MACHINE_ECHO_2)->equalsState(StateFactory::get(STATE_ECHO_2_NOTE))))
                {
                    // synchronize also TIME DIVISION ECHO1-ECHO2
                    MachineFactory::get(MACHINE_ECHO_2)->nextState();
                }
            }
            break;

        case PIN_BUTTON_PRIME_NUMBERS:
            MachineFactory::get(MACHINE_PRIME_NUMBERS)->nextState();
            break;
    }
}