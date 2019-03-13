#include "MidiProxy.h"

uint8_t MidiProxy::channel;

// https://github.com/FortySevenEffects/arduino_midi_library/blob/master/src/MIDI.h
// Send note 42 with velocity 127 on channel 1
// MIDI.sendNoteOn(42, 127, 1);

void MidiProxy::initialize()
{
    // Created and binds the MIDI interface to the default hardware Serial port
    MIDI_CREATE_DEFAULT_INSTANCE();

    // Default channel
    channel = MIDI_DEFAULT_CHANNEL;

    // Listen to all incoming messages
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void MidiProxy::setChannel(uint8_t newChannel)
{
    channel = newChannel;
}
