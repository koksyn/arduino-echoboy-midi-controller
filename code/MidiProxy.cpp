#include "MidiProxy.h"

uint8_t MidiProxy::channel;

void MidiProxy::initialize()
{
    // Default instance
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
