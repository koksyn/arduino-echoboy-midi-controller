#include "KnobManager.h"

ResponsiveAnalogRead* KnobManager::reading[KNOBS];

void KnobManager::initialize()
{
    for(byte knob = 0; knob < KNOBS; knob++) {
        // initialize reading
        reading[knob] = new ResponsiveAnalogRead(0, true);

        // update reading to initial knob position
        // it's important, because we avoid sending MIDI change signal after Power Up
        reading[knob]->update(readKnob(knob));
    }
}

byte lastSynchronizedEchoTime = EMPTY_SYNC;
short knobValue = 0;

void KnobManager::updateAllKnobs()
{
    knobValue = 0;

    if(readKnobAndSet(PIN_KNOB_ECHO_1_TIME)) {
        knobValue = reading[PIN_KNOB_ECHO_1_TIME]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);

        // Send MIDI
        MidiProxy::sendCC(CC_ECHO_1_TIME, knobValue);
        delay(5);
        MidiProxy::sendCC(CC_RHYTM_TIME, knobValue);
        // Update top LCD line
        LcdManager::printTop(knobValue);

        // check that timing of Echo1 & Echo2 is in SYNC or in SINGLE MODE
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED)) ||
           MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_SINGLE))) {
            // Send MIDI
            delay(5);
            MidiProxy::sendCC(CC_ECHO_2_TIME, knobValue);
            // Update bottom LCD line
            if(MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_SINGLE)) ||
               MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_RHYTM))
                    ) {
                LcdManager::clearBottom();
            } else {
                LcdManager::printBottom(knobValue);
            }

            lastSynchronizedEchoTime = knobValue;
        } else {
            lastSynchronizedEchoTime = EMPTY_SYNC;
        }
    }
    if(readKnobAndSet(PIN_KNOB_ECHO_2_TIME)) {
        knobValue = reading[PIN_KNOB_ECHO_2_TIME]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);

        // Send MIDI
        MidiProxy::sendCC(CC_ECHO_2_TIME, knobValue);
        delay(5);
        MidiProxy::sendCC(CC_RHYTM_TIME, knobValue);
        // Update bottom LCD line
        if(MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_SINGLE)) ||
           MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_RHYTM))
                ) {
            LcdManager::clearBottom();
        } else {
            LcdManager::printBottom(knobValue);
        }

        // check that timing of Echo1 & Echo2 is in SYNC or in SINGLE MODE
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED)) ||
           MachineFactory::get(MACHINE_MODE)->equalsState(StateFactory::get(STATE_MODE_SINGLE))) {
            // Send MIDI
            delay(5);
            MidiProxy::sendCC(CC_ECHO_1_TIME, knobValue);
            // Update top LCD line
            LcdManager::printTop(knobValue);

            lastSynchronizedEchoTime = knobValue;
        } else {
            lastSynchronizedEchoTime = EMPTY_SYNC;
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

boolean KnobManager::readKnobAndSet(uint8_t knobPinNumber)
{
    reading[knobPinNumber]->update(
      readKnob(knobPinNumber)
    );
    
    // this solution reduces electrical noise
    return reading[knobPinNumber]->hasChanged();
}

short KnobManager::readKnob(uint8_t knobPinNumber)
{
    return PinFactory::get(knobPinNumber)->read();
}

void KnobManager::forceAllKnobsToSendMIDI()
{
    knobValue = 0;

    // check that timing of Echo1 & Echo2 is in SYNC
    // or someone synchronized it earlier (but off the sync mode - without touching the knobs)
    if(
       MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED)) ||
       (lastSynchronizedEchoTime != EMPTY_SYNC)
    ) {
        // Send MIDI
        MidiProxy::sendCC(CC_ECHO_1_TIME, lastSynchronizedEchoTime);
        MidiProxy::sendCC(CC_ECHO_2_TIME, lastSynchronizedEchoTime);
        // Update LCD
        LcdManager::printTop(lastSynchronizedEchoTime);
        LcdManager::printBottom(lastSynchronizedEchoTime);
    }
    else {
        knobValue = reading[PIN_KNOB_ECHO_1_TIME]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_ECHO_1_TIME, knobValue);
        // Update top LCD line
        LcdManager::printTop(knobValue);

        knobValue = reading[PIN_KNOB_ECHO_2_TIME]->getValue();
        // map 10-bit value to MIDI(0-127)
        knobValue = map(knobValue, 1023, 0, 0, 127);
        // Send MIDI
        MidiProxy::sendCC(CC_ECHO_2_TIME, knobValue);
        // Update bottom LCD line
        LcdManager::printBottom(knobValue);
    }

    knobValue = reading[PIN_KNOB_FEEDBACK]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_FEEDBACK, knobValue);

    knobValue = reading[PIN_KNOB_MIX]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_MIX, knobValue);

    knobValue = reading[PIN_KNOB_SATURATION]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_SATURATION, knobValue);

    knobValue = reading[PIN_KNOB_LOW_CUT]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_LOW_CUT, knobValue);

    knobValue = reading[PIN_KNOB_HIGH_CUT]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_HIGH_CUT, knobValue);

    knobValue = reading[PIN_KNOB_INPUT]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_INPUT, knobValue);

    knobValue = reading[PIN_KNOB_OUTPUT]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_OUTPUT, knobValue);

    knobValue = reading[PIN_KNOB_FEEL]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_FEEL, knobValue);

    knobValue = reading[PIN_KNOB_GROOVE]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_GROOVE, knobValue);

    knobValue = reading[PIN_KNOB_RHYTM_REPEATS]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_RHYTM_REPEATS, knobValue);

    knobValue = reading[PIN_KNOB_RHYTM_DECAY]->getValue();
    // map 10-bit value to MIDI(0-127)
    knobValue = map(knobValue, 1023, 0, 0, 127);
    // Send MIDI
    MidiProxy::sendCC(CC_RHYTM_DECAY, knobValue);
}