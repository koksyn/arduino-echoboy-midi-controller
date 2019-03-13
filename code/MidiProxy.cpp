#include "MidiProxy.h"

void MidiProxy::initialize()
{
    // Default instance
    MIDI_CREATE_DEFAULT_INSTANCE();

    // Default channel
    this->channel = MIDI_DEFAULT_CHANNEL;

    // Listen to all incoming messages
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void MidiProxy::setChannel(uint8_t channel)
{
    this->channel = channel;
}
