#include "KnobManager.h"

ResponsiveAnalogRead* KnobManager::reading[KNOBS];

void KnobManager::initialize()
{ 
    for(int knob = 0; knob < KNOBS; knob++) {
        if(knob==PIN_KNOB_INPUT) continue;

        // initialize reading
        reading[knob] = new ResponsiveAnalogRead(0, true);
      
        int readedValue = readKnob(knob);

        // update reading to initial knob position
        // it's important, because we avoid sending MIDI change signal after Power Up
        reading[knob]->update(readedValue);
    }
}

void KnobManager::updateAllKnobs()
{
    if(readKnobAndSet(PIN_KNOB_ECHO_1_TIME)) {
        // send midi 1
        // lcd update 1

        // check that timing of Echo1 & Echo2 is in SYNC
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
            //lastKnobValue[PIN_KNOB_ECHO_2_TIME] = lastKnobValue[PIN_KNOB_ECHO_1_TIME];

            // send midi 2
            // lcd update 2
        }
    }
    if(readKnobAndSet(PIN_KNOB_ECHO_2_TIME)) {
        // send midi 2
        // lcd update 2

        // check that timing of Echo1 & Echo2 is in SYNC
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
            //lastKnobValue[PIN_KNOB_ECHO_1_TIME] = lastKnobValue[PIN_KNOB_ECHO_2_TIME];

            // send midi 1
            // lcd update 1
        }
    }
    if(readKnobAndSet(PIN_KNOB_FEEDBACK)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_MIX)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_SATURATION)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_LOW_CUT)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_HIGH_CUT)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_OUTPUT)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_FEEL)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_GROOVE)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_RHYTM_REPEATS)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_RHYTM_DECAY)) {
        // send midi
    }
}

// returns true if set was success
boolean KnobManager::readKnobAndSet(int knobPinNumber)
{
    reading[knobPinNumber]->update(
      readKnob(knobPinNumber)
    );
    
    // this solution reduces electrical noise
    if(reading[knobPinNumber]->hasChanged()) {        
        if(knobPinNumber == PIN_KNOB_ECHO_1_TIME)
        LcdManager::printTop(
            reading[knobPinNumber]->getValue()
        );
        
        if(knobPinNumber == PIN_KNOB_HIGH_CUT)
        LcdManager::printBottom(
            reading[knobPinNumber]->getValue()
        );
        
        return true;
    }
    
    return false;
}

int KnobManager::readKnob(uint8_t knobPinNumber)
{
    return PinFactory::get(knobPinNumber)->read();
    // map to midi values
    //return signal;//map(signal, 0, 255, 0, 127);
}
