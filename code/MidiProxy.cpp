#include "MidiProxy.h"

uint8_t MidiProxy::channel;

boolean MidiProxy::channelBtnLastValue[4];

// https://github.com/FortySevenEffects/arduino_midi_library/blob/master/src/MIDI.h

// Created and binds the MIDI interface to the Hairless MIDI Serial Bus
struct HairlessMidiSettings : public midi::DefaultSettings
{
    static const bool UseRunningStatus = false; // it's very important to have this 'extra' status disabled
    static const long BaudRate = SERIAL_MIDI_BIT_RATE;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, HairlessMidiSettings);

void MidiProxy::initialize()
{
    // Default channel
    channel = MIDI_DEFAULT_CHANNEL;

    // Listen to all incoming messages
    MIDI.begin(MIDI_CHANNEL_OMNI);

    listenForMidiChannelChanges();
}

void MidiProxy::setChannel(uint8_t newChannel)
{
    channel = newChannel;
}

void MidiProxy::sendCC(uint8_t controlNumber, uint8_t controlValue)
{
    MIDI.sendControlChange(controlNumber, controlValue, channel);
}

uint8_t channelReaded = 0;

void MidiProxy::listenForMidiChannelChanges()
{
    channelBtnLastValue[0] = !PinFactory::get(PIN_BUTTON_DIP_MIDI_4)->read();
    channelBtnLastValue[1] = !PinFactory::get(PIN_BUTTON_DIP_MIDI_3)->read();
    channelBtnLastValue[2] = !PinFactory::get(PIN_BUTTON_DIP_MIDI_2)->read();
    channelBtnLastValue[3] = !PinFactory::get(PIN_BUTTON_DIP_MIDI_1)->read();

    // readed Channel binary number (+1 because we shift by that 0-15 to midi 1-16)
    channelReaded = boolArrayToByte(channelBtnLastValue) + 1;

    // check that it differs from defaults
    if(channelReaded != channel) {
        channel = channelReaded;
    }
}

uint8_t result = 0;
byte i = 0;

uint8_t MidiProxy::boolArrayToByte(bool* boolArray)
{
    result = 0;

    for(i = 0; i < 4; i++)
    {
        if(*(boolArray + i))
        {
            result = result | (1 << i);
        }
    }

    return result;
}