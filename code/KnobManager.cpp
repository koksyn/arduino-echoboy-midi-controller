#include "KnobManager.h"

ResponsiveAnalogRead* KnobManager::reading[KNOBS];

void KnobManager::initialize()
{ 
    for(int knob = 0; knob < KNOBS; knob++) {
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
    int knobValue = 0;

    if(readKnobAndSet(PIN_KNOB_ECHO_1_TIME)) {
        knobValue = reading[PIN_KNOB_ECHO_1_TIME]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);

        // Send MIDI
        MidiProxy::sendCC(CC_ECHO_1_TIME, knobValue);
        // Update top LCD line
        LcdManager::printTop(knobValue);

        // check that timing of Echo1 & Echo2 is in SYNC
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
            // Send MIDI
            MidiProxy::sendCC(CC_ECHO_2_TIME, knobValue);
            // Update bottom LCD line
            LcdManager::printBottom(knobValue);
        }
    }
    if(readKnobAndSet(PIN_KNOB_ECHO_2_TIME)) {
        knobValue = reading[PIN_KNOB_ECHO_2_TIME]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);

        // Send MIDI
        MidiProxy::sendCC(CC_ECHO_2_TIME, knobValue);
        // Update bottom LCD line
        LcdManager::printBottom(knobValue);

        // check that timing of Echo1 & Echo2 is in SYNC
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
            // Send MIDI
            MidiProxy::sendCC(CC_ECHO_1_TIME, knobValue);
            // Update top LCD line
            LcdManager::printTop(knobValue);
        }
    }
    if(readKnobAndSet(PIN_KNOB_FEEDBACK)) {
        knobValue = reading[PIN_KNOB_FEEDBACK]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_FEEDBACK, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_MIX)) {
        knobValue = reading[PIN_KNOB_MIX]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_MIX, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_SATURATION)) {
        knobValue = reading[PIN_KNOB_SATURATION]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_SATURATION, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_LOW_CUT)) {
        knobValue = reading[PIN_KNOB_LOW_CUT]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_LOW_CUT, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_HIGH_CUT)) {
        knobValue = reading[PIN_KNOB_HIGH_CUT]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_HIGH_CUT, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_INPUT)) {
        knobValue = reading[PIN_KNOB_INPUT]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_INPUT, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_OUTPUT)) {
        knobValue = reading[PIN_KNOB_OUTPUT]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_OUTPUT, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_FEEL)) {
        knobValue = reading[PIN_KNOB_FEEL]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_FEEL, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_GROOVE)) {
        knobValue = reading[PIN_KNOB_GROOVE]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_GROOVE, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_RHYTM_REPEATS)) {
        knobValue = reading[PIN_KNOB_RHYTM_REPEATS]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_RHYTM_REPEATS, knobValue);
    }
    if(readKnobAndSet(PIN_KNOB_RHYTM_DECAY)) {
        knobValue = reading[PIN_KNOB_RHYTM_DECAY]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_RHYTM_DECAY, knobValue);
    }
}

boolean KnobManager::readKnobAndSet(int knobPinNumber)
{
    reading[knobPinNumber]->update(
      readKnob(knobPinNumber)
    );
    
    // this solution reduces electrical noise
    return reading[knobPinNumber]->hasChanged();
}

int KnobManager::readKnob(uint8_t knobPinNumber)
{
    return PinFactory::get(knobPinNumber)->read();
}
