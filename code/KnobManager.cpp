#include "KnobManager.h"

uint8_t KnobManager::lastKnobValue[KNOBS];

void KnobManager::initialize()
{
    lastKnobValue[PIN_KNOB_ECHO_1_TIME] = readKnob(PIN_KNOB_ECHO_1_TIME);
    lastKnobValue[PIN_KNOB_ECHO_2_TIME] = readKnob(PIN_KNOB_ECHO_2_TIME);
    lastKnobValue[PIN_KNOB_FEEDBACK] = readKnob(PIN_KNOB_FEEDBACK);
    lastKnobValue[PIN_KNOB_MIX] = readKnob(PIN_KNOB_MIX);
    lastKnobValue[PIN_KNOB_SATURATION] = readKnob(PIN_KNOB_SATURATION);
    lastKnobValue[PIN_KNOB_LOW_CUT] = readKnob(PIN_KNOB_LOW_CUT);
    lastKnobValue[PIN_KNOB_HIGH_CUT] = readKnob(PIN_KNOB_HIGH_CUT);
    lastKnobValue[PIN_KNOB_OUTPUT] = readKnob(PIN_KNOB_OUTPUT);
    lastKnobValue[PIN_KNOB_FEEL] = readKnob(PIN_KNOB_FEEL);
    lastKnobValue[PIN_KNOB_GROOVE] = readKnob(PIN_KNOB_GROOVE);
    lastKnobValue[PIN_KNOB_RHYTM_REPEATS] = readKnob(PIN_KNOB_RHYTM_REPEATS);
    lastKnobValue[PIN_KNOB_RHYTM_DECAY] = readKnob(PIN_KNOB_RHYTM_DECAY);
}

void KnobManager::updateAllKnobs()
{
    if(readKnobAndSet(PIN_KNOB_ECHO_1_TIME)) {
        // send midi 1
        // lcd update 1

        // check that timing of Echo1 & Echo2 is in SYNC
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
            lastKnobValue[PIN_KNOB_ECHO_2_TIME] = lastKnobValue[PIN_KNOB_ECHO_1_TIME];

            // send midi 2
            // lcd update 2
        }
    }
    if(readKnobAndSet(PIN_KNOB_ECHO_2_TIME)) {
        // send midi 2
        // lcd update 2

        // check that timing of Echo1 & Echo2 is in SYNC
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
            lastKnobValue[PIN_KNOB_ECHO_1_TIME] = lastKnobValue[PIN_KNOB_ECHO_2_TIME];

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
boolean KnobManager::readKnobAndSet(uint8_t knobPinNumber)
{
    uint8_t newValue = readKnob(knobPinNumber);

    // exceeding marginal value will allow to change lastValue of knob
    // this solution reduces electrical noise
    boolean allowedToSet = knobValueExceededMargin(knobPinNumber, newValue, 3);

    if(allowedToSet) {
        lastKnobValue[knobPinNumber] = newValue;
        return true;
    }

    return false;
}

uint8_t KnobManager::readKnob(uint8_t knobPinNumber)
{
    uint8_t signal = PinFactory::get(knobPinNumber)->read();

    // map to midi values
    return map(signal, 0, 255, 0, 127);
}

boolean KnobManager::knobValueExceededMargin(uint8_t knobPinNumber, uint8_t newValue, uint8_t marginalValue)
{
    return valueNotBetween(
            newValue,
            lastKnobValue[knobPinNumber] - marginalValue,
            lastKnobValue[knobPinNumber] + marginalValue
    );
}

boolean KnobManager::valueNotBetween(uint8_t value, uint8_t x, uint8_t y)
{
    return (value < x) || (value > y);
}
