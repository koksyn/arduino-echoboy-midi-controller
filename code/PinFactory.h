#ifndef PIN_FACTORY_H
#define PIN_FACTORY_H

#include <Adafruit_MCP3008.h>
#include <PCF8574.h>

#include "Pin.h"

// ARDUINO Analog for Knobs
#define PIN_KNOB_ECHO_1_TIME     0
#define PIN_KNOB_ECHO_2_TIME     1
#define PIN_KNOB_FEEDBACK        2
#define PIN_KNOB_MIX             3
#define PIN_KNOB_SATURATION      4
#define PIN_KNOB_LOW_CUT         5

// MCP3008 Analog for Knobs
#define PIN_KNOB_HIGH_CUT        6
#define PIN_KNOB_INPUT           7
#define PIN_KNOB_OUTPUT          8
#define PIN_KNOB_FEEL            9
#define PIN_KNOB_GROOVE          10
#define PIN_KNOB_RHYTM_REPEATS   11
#define PIN_KNOB_RHYTM_DECAY     12

// ARDUINO Digital
#define PIN_BUTTON_DIP_MIDI_4   13
#define PIN_INT_FROM_PCF        14
#define PIN_LED_MIDI_ALL        15
#define PIN_LED_BYPASS          16
#define PIN_LED_SYNC_TIME       17
#define PIN_LED_PRIME_NUMBERS   18

// PCF 1 (INT) for BUTTONS
#define PIN_BUTTON_DIP_MIDI_3       19
#define PIN_BUTTON_DIP_MIDI_2       20
#define PIN_BUTTON_DIP_MIDI_1       21
#define PIN_BUTTON_MODE             22
#define PIN_BUTTON_ECHO_1           23
#define PIN_BUTTON_ECHO_2           24
#define PIN_BUTTON_SYNC_TIME        25
#define PIN_BUTTON_PRIME_NUMBERS    26

// PCF 2 (INT) for BUTTONS
#define PIN_BUTTON_STYLE_TAPE   27
#define PIN_BUTTON_STYLE_ECHO   28
#define PIN_BUTTON_STYLE_BBD    29
#define PIN_BUTTON_STYLE_BIAS   30
#define PIN_BUTTON_STYLE_CHORUS 31
#define PIN_BUTTON_STYLE_ATMO   32
#define PIN_BUTTON_MIDI_ALL     33
#define PIN_BUTTON_BYPASS       34

// PCF 3 for LED
#define PIN_LED_TAPE_STUDIO     35
#define PIN_LED_TAPE_CHEAP      36
#define PIN_LED_TAPE_TUBE       37
#define PIN_LED_TAPE_MASTER     38
#define PIN_LED_ECHO_PLEX       39
#define PIN_LED_ECHO_SPACE      40
#define PIN_LED_ECHO_TEL_RAY    41
#define PIN_LED_ECHO_BINSONETTE 42

// PCF 4 for LED
#define PIN_LED_BBD_MEMORY_MAN      43
#define PIN_LED_BBD_ANALOG          44
#define PIN_LED_BBD_AM_RADIO        45
#define PIN_LED_BBD_DM_2            46
#define PIN_LED_BIAS_TRANSMITTER    47
#define PIN_LED_BIAS_DISTORTED      48
#define PIN_LED_BIAS_SATURATED      49
#define PIN_LED_BIAS_QUEEKED        50

// PCF 5 for LED
#define PIN_LED_CHORUS_CE_1     51
#define PIN_LED_CHORUS_ANALOG   52
#define PIN_LED_CHORUS_VIBRATO  53
#define PIN_LED_CHORUS_DIGITAL  54
#define PIN_LED_ATMO_AMBIENT    55
#define PIN_LED_ATMO_VERBED     56
#define PIN_LED_ATMO_DIFFUSED   57
#define PIN_LED_ATMO_SPLATTERED 58

// PCF 6 for LED
#define PIN_LED_MODE_PING_PONG  59
#define PIN_LED_MODE_DUAL       60
#define PIN_LED_MODE_RHYTM      61
#define PIN_LED_MODE_SINGLE     62
#define PIN_LED_ECHO_1_TIME     63
#define PIN_LED_ECHO_1_NOTE     64
#define PIN_LED_ECHO_2_TIME     65
#define PIN_LED_ECHO_2_NOTE     66

// AMOUNT OF PINS
#define PINS 67

class PinFactory {
private:
    static Pin* pins[PINS];

    static Adafruit_MCP3008* analogDigitalConverter;
    static PCF8574* buttonExpander;
    static PCF8574* buttonExpander2;
    static PCF8574* ledExpander;
    static PCF8574* ledExpander2;
    static PCF8574* ledExpander3;
    static PCF8574* ledExpander4;
public:
    static void initialize();
    
    // exposed for interruption handling
    static PCF8574* getButtonExpander();
    static PCF8574* getButtonExpander2();

    static Pin* get(int key);
    static void runIntegratedCircuits();
};

#endif
