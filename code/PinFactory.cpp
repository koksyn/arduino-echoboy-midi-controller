#include "PinFactory.h"
#include "ArduinoDigitalPin.h"
#include "ArduinoAnalogPin.h"
#include "Mcp3008Pin.h"
#include "Pcf8574Pin.h"

Pin* PinFactory::pins[PINS];

// initialize MCP3008 analog to digital converter
Adafruit_MCP3008* PinFactory::analogDigitalConverter = new Adafruit_MCP3008();

// initailize PCF8574 digital I/O expanders
PCF8574* PinFactory::buttonExpander = new PCF8574();
PCF8574* PinFactory::buttonExpander2 = new PCF8574();
PCF8574* PinFactory::ledExpander = new PCF8574();
PCF8574* PinFactory::ledExpander2 = new PCF8574();
PCF8574* PinFactory::ledExpander3 = new PCF8574();
PCF8574* PinFactory::ledExpander4 = new PCF8574();

void PinFactory::initialize()
{
    // ARDUINO Analog for Knobs
    pins[PIN_KNOB_ECHO_1_TIME] = (Pin*) new ArduinoAnalogPin(A0, INPUT);
    pins[PIN_KNOB_OUTPUT] = (Pin*) new ArduinoAnalogPin(A1, INPUT);
    pins[PIN_KNOB_INPUT] = (Pin*) new ArduinoAnalogPin(A2, INPUT);
    pins[PIN_KNOB_HIGH_CUT] = (Pin*) new ArduinoAnalogPin(A4, INPUT);
    pins[PIN_KNOB_LOW_CUT] = (Pin*) new ArduinoAnalogPin(A5, INPUT);

    // MCP3008 Analog for Knobs
    pins[PIN_KNOB_RHYTM_REPEATS] = (Pin*) new Mcp3008Pin(0, INPUT, analogDigitalConverter);
    pins[PIN_KNOB_RHYTM_DECAY] = (Pin*) new Mcp3008Pin(1, INPUT, analogDigitalConverter);
    pins[PIN_KNOB_MIX] = (Pin*) new Mcp3008Pin(2, INPUT, analogDigitalConverter);
    pins[PIN_KNOB_SATURATION] = (Pin*) new Mcp3008Pin(3, INPUT, analogDigitalConverter);
    pins[PIN_KNOB_FEEDBACK] = (Pin*) new Mcp3008Pin(4, INPUT, analogDigitalConverter);
    pins[PIN_KNOB_FEEL] = (Pin*) new Mcp3008Pin(5, INPUT, analogDigitalConverter);
    pins[PIN_KNOB_GROOVE] = (Pin*) new Mcp3008Pin(6, INPUT, analogDigitalConverter);
    pins[PIN_KNOB_ECHO_2_TIME] = (Pin*) new Mcp3008Pin(7, INPUT, analogDigitalConverter);

    // ARDUINO Digital
    pins[PIN_INT_FROM_PCF] = (Pin*) new ArduinoDigitalPin(2, INPUT_PULLUP);
    pins[PIN_INT_FROM_PCF_2] = (Pin*) new ArduinoDigitalPin(3, INPUT_PULLUP);
    pins[PIN_LED_MIDI_ALL] = (Pin*) new ArduinoDigitalPin(4, OUTPUT);
    pins[PIN_LED_BYPASS] = (Pin*) new ArduinoDigitalPin(5, OUTPUT);
    pins[PIN_LED_SYNC_TIME] = (Pin*) new ArduinoDigitalPin(6, OUTPUT);
    pins[PIN_LED_PRIME_NUMBERS] = (Pin*) new ArduinoDigitalPin(7, OUTPUT);

    // PCF 1 (INT) for BUTTONS ----- 0x38
    pins[PIN_BUTTON_DIP_MIDI_3] = (Pin*) new Pcf8574Pin(0, INPUT_PULLUP, buttonExpander);
    pins[PIN_BUTTON_DIP_MIDI_2] = (Pin*) new Pcf8574Pin(1, INPUT_PULLUP, buttonExpander);
    pins[PIN_BUTTON_DIP_MIDI_1] = (Pin*) new Pcf8574Pin(2, INPUT_PULLUP, buttonExpander);
    pins[PIN_BUTTON_BYPASS] = (Pin*) new Pcf8574Pin(3, INPUT_PULLUP, buttonExpander);
    pins[PIN_BUTTON_ECHO_1] = (Pin*) new Pcf8574Pin(4, INPUT_PULLUP, buttonExpander);
    pins[PIN_BUTTON_STYLE_BIAS] = (Pin*) new Pcf8574Pin(5, INPUT_PULLUP, buttonExpander);
    pins[PIN_BUTTON_STYLE_CHORUS] = (Pin*) new Pcf8574Pin(6, INPUT_PULLUP, buttonExpander);
    pins[PIN_BUTTON_STYLE_ATMO] = (Pin*) new Pcf8574Pin(7, INPUT_PULLUP, buttonExpander);

    // PCF 2 (INT) for BUTTONS ----- 0x39
    pins[PIN_BUTTON_MODE] = (Pin*) new Pcf8574Pin(0, INPUT_PULLUP, buttonExpander2);
    pins[PIN_BUTTON_STYLE_TAPE] = (Pin*) new Pcf8574Pin(1, INPUT_PULLUP, buttonExpander2);
    pins[PIN_BUTTON_STYLE_ECHO] = (Pin*) new Pcf8574Pin(2, INPUT_PULLUP, buttonExpander2);
    pins[PIN_BUTTON_SYNC_TIME] = (Pin*) new Pcf8574Pin(3, INPUT_PULLUP, buttonExpander2);
    pins[PIN_BUTTON_PRIME_NUMBERS] = (Pin*) new Pcf8574Pin(4, INPUT_PULLUP, buttonExpander2);
    pins[PIN_BUTTON_MIDI_ALL] = (Pin*) new Pcf8574Pin(5, INPUT_PULLUP, buttonExpander2);
    pins[PIN_BUTTON_ECHO_2] = (Pin*) new Pcf8574Pin(6, INPUT_PULLUP, buttonExpander2);
    pins[PIN_BUTTON_STYLE_BBD] = (Pin*) new Pcf8574Pin(7, INPUT_PULLUP, buttonExpander2);

    // PCF 3 for LED ----- 0x3A
    pins[PIN_LED_ATMO_DIFFUSED] = (Pin*) new Pcf8574Pin(0, OUTPUT, ledExpander);
    pins[PIN_LED_ATMO_SPLATTERED] = (Pin*) new Pcf8574Pin(1, OUTPUT, ledExpander);
    pins[PIN_LED_BBD_AM_RADIO] = (Pin*) new Pcf8574Pin(2, OUTPUT, ledExpander);
    pins[PIN_LED_BBD_DM_2] = (Pin*) new Pcf8574Pin(3, OUTPUT, ledExpander);
    pins[PIN_LED_CHORUS_DIGITAL] = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander);
    pins[PIN_LED_ATMO_VERBED] = (Pin*) new Pcf8574Pin(5, OUTPUT, ledExpander);
    pins[PIN_LED_CHORUS_VIBRATO] = (Pin*) new Pcf8574Pin(6, OUTPUT, ledExpander);
    pins[PIN_LED_CHORUS_ANALOG] = (Pin*) new Pcf8574Pin(7, OUTPUT, ledExpander);

    // PCF 4 for LED ----- 0x3B
    pins[PIN_LED_BIAS_SATURATED] = (Pin*) new Pcf8574Pin(0, OUTPUT, ledExpander2);
    pins[PIN_LED_BIAS_QUEEKED] = (Pin*) new Pcf8574Pin(1, OUTPUT, ledExpander2);
    pins[PIN_LED_CHORUS_CE_1] = (Pin*) new Pcf8574Pin(2, OUTPUT, ledExpander2);
    pins[PIN_LED_ATMO_AMBIENT] = (Pin*) new Pcf8574Pin(3, OUTPUT, ledExpander2);
    pins[PIN_LED_ECHO_BINSONETTE] = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander2);
    pins[PIN_LED_BBD_MEMORY_MAN] = (Pin*) new Pcf8574Pin(5, OUTPUT, ledExpander2);
    pins[PIN_LED_BIAS_DISTORTED] = (Pin*) new Pcf8574Pin(6, OUTPUT, ledExpander2);
    pins[PIN_LED_BIAS_TRANSMITTER] = (Pin*) new Pcf8574Pin(7, OUTPUT, ledExpander2);

    // PCF 5 for LED ----- 0x3C
    pins[PIN_LED_ECHO_TEL_RAY] = (Pin*) new Pcf8574Pin(0, OUTPUT, ledExpander3);
    pins[PIN_LED_ECHO_SPACE] = (Pin*) new Pcf8574Pin(1, OUTPUT, ledExpander3);
    pins[PIN_LED_ECHO_1_TIME] = (Pin*) new Pcf8574Pin(2, OUTPUT, ledExpander3);
    pins[PIN_LED_ECHO_1_NOTE] = (Pin*) new Pcf8574Pin(3, OUTPUT, ledExpander3);
    pins[PIN_LED_TAPE_MASTER] = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander3);
    pins[PIN_LED_ECHO_PLEX] = (Pin*) new Pcf8574Pin(5, OUTPUT, ledExpander3);
    pins[PIN_LED_BBD_ANALOG] = (Pin*) new Pcf8574Pin(6, OUTPUT, ledExpander3);
    pins[PIN_LED_TAPE_TUBE] = (Pin*) new Pcf8574Pin(7, OUTPUT, ledExpander3);

    // PCF 6 for LED ----- 0x3D
    pins[PIN_LED_TAPE_STUDIO] = (Pin*) new Pcf8574Pin(0, OUTPUT, ledExpander4);
    pins[PIN_LED_TAPE_CHEAP] = (Pin*) new Pcf8574Pin(1, OUTPUT, ledExpander4);
    pins[PIN_LED_ECHO_2_NOTE] = (Pin*) new Pcf8574Pin(2, OUTPUT, ledExpander4);
    pins[PIN_LED_ECHO_2_TIME] = (Pin*) new Pcf8574Pin(3, OUTPUT, ledExpander4);
    pins[PIN_LED_MODE_PING_PONG] = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander4);
    pins[PIN_LED_MODE_DUAL] = (Pin*) new Pcf8574Pin(5, OUTPUT, ledExpander4);
    pins[PIN_LED_MODE_RHYTM] = (Pin*) new Pcf8574Pin(6, OUTPUT, ledExpander4);
    pins[PIN_LED_MODE_SINGLE] = (Pin*) new Pcf8574Pin(7, OUTPUT, ledExpander4);
}

PCF8574* PinFactory::getButtonExpander()
{
    return buttonExpander;
}

PCF8574* PinFactory::getButtonExpander2()
{
    return buttonExpander2;
}

Pin* PinFactory::get(int key)
{
    return pins[key];
}

void PinFactory::runIntegratedCircuits()
{
    // Arduino Analog + MCP3008 + Arduino Digital
    for(uint8_t i=0; i<PIN_BUTTON_DIP_MIDI_3; i++) {
        pins[i]->applyMode();
    }

    analogDigitalConverter->begin();

/*
    buttonExpander->begin(0x38);
    buttonExpander2->begin(0x39);

    ledExpander->begin(0x3A);
    ledExpander2->begin(0x3B);
    ledExpander3->begin(0x3C);
    ledExpander4->begin(0x3D);

    // PCF 1,2,3,4,5,6
    for(uint8_t i=PIN_BUTTON_DIP_MIDI_3; i<PINS; i++) {
        pins[i]->applyMode();
    }*/
}
