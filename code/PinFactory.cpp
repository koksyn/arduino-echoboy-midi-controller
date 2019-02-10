#include "PinFactory.h"

#include <ArduinoSTL.h>
#include <map>
#include "ArduinoDigitalPin.h"
#include "ArduinoAnalogPin.h"
#include "Mcp3008Pin.h"
#include "Pcf8574Pin.h"

std::map<String, Pin*> PinFactory::pins;

// initialize MCP3008 analog to digital converter
Adafruit_MCP3008* PinFactory::analogDigitalConverter = new Adafruit_MCP3008();

// initailize PCF8574 digital I/O expanders
PCF8574* PinFactory::buttonExpander = new PCF8574();
PCF8574* PinFactory::buttonExpander2 = new PCF8574();
PCF8574* PinFactory::ledExpander = new PCF8574();
PCF8574* PinFactory::ledExpander2 = new PCF8574();
PCF8574* PinFactory::ledExpander3 = new PCF8574();
PCF8574* PinFactory::ledExpander4 = new PCF8574();

bool PinFactory::notInitialized()
{
    return pins.empty();
}

void PinFactory::initialize()
{
    // ARDUINO Analog for POTS
    Pin* echo1TimePot = (Pin*) new ArduinoAnalogPin(A0, INPUT);
    Pin* echo2TimePot = (Pin*) new ArduinoAnalogPin(A1, INPUT);
    Pin* feedbackPot = (Pin*) new ArduinoAnalogPin(A2, INPUT);
    Pin* mixPot = (Pin*) new ArduinoAnalogPin(A3, INPUT);
    Pin* saturationPot = (Pin*) new ArduinoAnalogPin(A4, INPUT);
    Pin* lowCutPot = (Pin*) new ArduinoAnalogPin(A5, INPUT);

    pins.insert(std::pair<String, Pin*>("Echo1TimePot", echo1TimePot));
    pins.insert(std::pair<String, Pin*>("Echo2TimePot", echo2TimePot));
    pins.insert(std::pair<String, Pin*>("FeedbackPot", feedbackPot));
    pins.insert(std::pair<String, Pin*>("MixPot", mixPot));
    pins.insert(std::pair<String, Pin*>("SaturationPot", saturationPot));
    pins.insert(std::pair<String, Pin*>("LowCutPot", lowCutPot));

    // MCP3008 Analog for POTS
    Pin* highCutPot = (Pin*) new Mcp3008Pin(0, INPUT, analogDigitalConverter);
    Pin* inputPot = (Pin*) new Mcp3008Pin(1, INPUT, analogDigitalConverter);
    Pin* outputPot = (Pin*) new Mcp3008Pin(2, INPUT, analogDigitalConverter);
    Pin* feelPot = (Pin*) new Mcp3008Pin(3, INPUT, analogDigitalConverter);
    Pin* groovePot = (Pin*) new Mcp3008Pin(4, INPUT, analogDigitalConverter);
    Pin* rhytmRepeatsPot = (Pin*) new Mcp3008Pin(5, INPUT, analogDigitalConverter);
    Pin* rhytmDecayPot = (Pin*) new Mcp3008Pin(6, INPUT, analogDigitalConverter);

    pins.insert(std::pair<String, Pin*>("HighCutPot", highCutPot));
    pins.insert(std::pair<String, Pin*>("InputPot", inputPot));
    pins.insert(std::pair<String, Pin*>("OutputPot", outputPot));
    pins.insert(std::pair<String, Pin*>("FeelPot", feelPot));
    pins.insert(std::pair<String, Pin*>("GroovePot", groovePot));
    pins.insert(std::pair<String, Pin*>("RhytmRepeatsPot", rhytmRepeatsPot));
    pins.insert(std::pair<String, Pin*>("RhytmDecayPot", rhytmDecayPot));

    // ARDUINO Digital
    Pin* dipMidi1 = (Pin*) new ArduinoDigitalPin(2, INPUT_PULLUP);
    Pin* interruptForPCF = (Pin*) new ArduinoDigitalPin(3, INPUT);
    Pin* midiAllLed = (Pin*) new ArduinoDigitalPin(4, OUTPUT);
    Pin* bypassLed = (Pin*) new ArduinoDigitalPin(5, OUTPUT);
    Pin* syncTimeLed = (Pin*) new ArduinoDigitalPin(6, OUTPUT);
    Pin* primeNumbersLed = (Pin*) new ArduinoDigitalPin(7, OUTPUT);

    pins.insert(std::pair<String, Pin*>("DipMidi1", dipMidi1));
    pins.insert(std::pair<String, Pin*>("InterruptForPCF", interruptForPCF));
    pins.insert(std::pair<String, Pin*>("MidiAllLed", midiAllLed));
    pins.insert(std::pair<String, Pin*>("BypassLed", bypassLed));
    pins.insert(std::pair<String, Pin*>("SyncTimeLed", syncTimeLed));
    pins.insert(std::pair<String, Pin*>("PrimeNumbersLed", primeNumbersLed));

    // PCF 1 (INT) for BUTTONS
    Pin* dipMidi2 = (Pin*) new Pcf8574Pin(0, INPUT_PULLUP, buttonExpander);
    Pin* dipMidi3 = (Pin*) new Pcf8574Pin(1, INPUT_PULLUP, buttonExpander);
    Pin* dipMidi4 = (Pin*) new Pcf8574Pin(2, INPUT_PULLUP, buttonExpander);
    Pin* modeButton = (Pin*) new Pcf8574Pin(3, INPUT_PULLUP, buttonExpander);
    Pin* echo1Button = (Pin*) new Pcf8574Pin(4, INPUT_PULLUP, buttonExpander);
    Pin* echo2Button = (Pin*) new Pcf8574Pin(5, INPUT_PULLUP, buttonExpander);
    Pin* syncTimeButton = (Pin*) new Pcf8574Pin(6, INPUT_PULLUP, buttonExpander);
    Pin* primeNumbersButton = (Pin*) new Pcf8574Pin(7, INPUT_PULLUP, buttonExpander);

    pins.insert(std::pair<String, Pin*>("DipMidi2", dipMidi2));
    pins.insert(std::pair<String, Pin*>("DipMidi3", dipMidi3));
    pins.insert(std::pair<String, Pin*>("DipMidi4", dipMidi4));
    pins.insert(std::pair<String, Pin*>("ModeButton", modeButton));
    pins.insert(std::pair<String, Pin*>("Echo1Button", echo1Button));
    pins.insert(std::pair<String, Pin*>("Echo2Button", echo2Button));
    pins.insert(std::pair<String, Pin*>("SyncTimeButton", syncTimeButton));
    pins.insert(std::pair<String, Pin*>("PrimeNumbersButton", primeNumbersButton));

    // PCF 2 (INT) for BUTTONS
    Pin* tapeStyleButton = (Pin*) new Pcf8574Pin(0, INPUT_PULLUP, buttonExpander2);
    Pin* echoStyleButton = (Pin*) new Pcf8574Pin(1, INPUT_PULLUP, buttonExpander2);
    Pin* bbdStyleButton = (Pin*) new Pcf8574Pin(2, INPUT_PULLUP, buttonExpander2);
    Pin* biasStyleButton = (Pin*) new Pcf8574Pin(3, INPUT_PULLUP, buttonExpander2);
    Pin* chorusStyleButton = (Pin*) new Pcf8574Pin(4, INPUT_PULLUP, buttonExpander2);
    Pin* atmoStyleButton = (Pin*) new Pcf8574Pin(5, INPUT_PULLUP, buttonExpander2);
    Pin* midiAllButton = (Pin*) new Pcf8574Pin(6, INPUT_PULLUP, buttonExpander2);
    Pin* bypassButton = (Pin*) new Pcf8574Pin(7, INPUT_PULLUP, buttonExpander2);

    pins.insert(std::pair<String, Pin*>("TapeStyleButton", tapeStyleButton));
    pins.insert(std::pair<String, Pin*>("EchoStyleButton", echoStyleButton));
    pins.insert(std::pair<String, Pin*>("BbdStyleButton", bbdStyleButton));
    pins.insert(std::pair<String, Pin*>("BiasStyleButton", biasStyleButton));
    pins.insert(std::pair<String, Pin*>("ChorusStyleButton", chorusStyleButton));
    pins.insert(std::pair<String, Pin*>("AtmoStyleButton", atmoStyleButton));
    pins.insert(std::pair<String, Pin*>("MidiAllButton", midiAllButton));
    pins.insert(std::pair<String, Pin*>("BypassButton", bypassButton));

    // PCF 3 for LED
    Pin* studioTapeLed = (Pin*) new Pcf8574Pin(0, OUTPUT, ledExpander);
    Pin* cheapTapeLed = (Pin*) new Pcf8574Pin(1, OUTPUT, ledExpander);
    Pin* tubeTapeLed = (Pin*) new Pcf8574Pin(2, OUTPUT, ledExpander);
    Pin* masterTapeLed = (Pin*) new Pcf8574Pin(3, OUTPUT, ledExpander);
    Pin* plexEchoLed = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander);
    Pin* spaceEchoLed = (Pin*) new Pcf8574Pin(5, OUTPUT, ledExpander);
    Pin* telrayEchoLed = (Pin*) new Pcf8574Pin(6, OUTPUT, ledExpander);
    Pin* binsonetteEchoLed = (Pin*) new Pcf8574Pin(7, OUTPUT, ledExpander);

    pins.insert(std::pair<String, Pin*>("StudioTapeLed", studioTapeLed));
    pins.insert(std::pair<String, Pin*>("CheapTapeLed", cheapTapeLed));
    pins.insert(std::pair<String, Pin*>("TubeTapeLed", tubeTapeLed));
    pins.insert(std::pair<String, Pin*>("MasterTapeLed", masterTapeLed));
    pins.insert(std::pair<String, Pin*>("PlexEchoLed", plexEchoLed));
    pins.insert(std::pair<String, Pin*>("SpaceEchoLed", spaceEchoLed));
    pins.insert(std::pair<String, Pin*>("TelrayEchoLed", telrayEchoLed));
    pins.insert(std::pair<String, Pin*>("BinsonetteEchoLed", binsonetteEchoLed));

    // PCF 4 for LED
    Pin* memoryManBbdLed = (Pin*) new Pcf8574Pin(0, OUTPUT, ledExpander2);
    Pin* analogBbdLed = (Pin*) new Pcf8574Pin(1, OUTPUT, ledExpander2);
    Pin* amRadioBbdLed = (Pin*) new Pcf8574Pin(2, OUTPUT, ledExpander2);
    Pin* dm2BbdLed = (Pin*) new Pcf8574Pin(3, OUTPUT, ledExpander2);
    Pin* transmitterBiasLed = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander2);
    Pin* distortedBiasLed = (Pin*) new Pcf8574Pin(5, OUTPUT, ledExpander2);
    Pin* saturatedBiasLed = (Pin*) new Pcf8574Pin(6, OUTPUT, ledExpander2);
    Pin* queekedBiasLed = (Pin*) new Pcf8574Pin(7, OUTPUT, ledExpander2);

    pins.insert(std::pair<String, Pin*>("MemoryManBbdLed", memoryManBbdLed));
    pins.insert(std::pair<String, Pin*>("AnalogBbdLed", analogBbdLed));
    pins.insert(std::pair<String, Pin*>("AmRadioBbdLed", amRadioBbdLed));
    pins.insert(std::pair<String, Pin*>("Dm2BbdLed", dm2BbdLed));
    pins.insert(std::pair<String, Pin*>("TransmitterBiasLed", transmitterBiasLed));
    pins.insert(std::pair<String, Pin*>("DistortedBiasLed", distortedBiasLed));
    pins.insert(std::pair<String, Pin*>("SaturatedBiasLed", saturatedBiasLed));
    pins.insert(std::pair<String, Pin*>("QueekedBiasLed", queekedBiasLed));

    // PCF 5 for LED
    Pin* ce1ChorusLed = (Pin*) new Pcf8574Pin(0, OUTPUT, ledExpander3);
    Pin* analogChorusLed = (Pin*) new Pcf8574Pin(1, OUTPUT, ledExpander3);
    Pin* vibratoChorusLed = (Pin*) new Pcf8574Pin(2, OUTPUT, ledExpander3);
    Pin* digitalChorusLed = (Pin*) new Pcf8574Pin(3, OUTPUT, ledExpander3);
    Pin* ambientAtmoLed = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander3);
    Pin* verbedAtmoLed = (Pin*) new Pcf8574Pin(5, OUTPUT, ledExpander3);
    Pin* diffusedAtmoLed = (Pin*) new Pcf8574Pin(6, OUTPUT, ledExpander3);
    Pin* splatteredAtmoLed = (Pin*) new Pcf8574Pin(7, OUTPUT, ledExpander3);

    pins.insert(std::pair<String, Pin*>("Ce1ChorusLed", ce1ChorusLed));
    pins.insert(std::pair<String, Pin*>("AnalogChorusLed", analogChorusLed));
    pins.insert(std::pair<String, Pin*>("VibratoChorusLed", vibratoChorusLed));
    pins.insert(std::pair<String, Pin*>("DigitalChorusLed", digitalChorusLed));
    pins.insert(std::pair<String, Pin*>("AmbientAtmoLed", ambientAtmoLed));
    pins.insert(std::pair<String, Pin*>("VerbedAtmoLed", verbedAtmoLed));
    pins.insert(std::pair<String, Pin*>("DiffusedAtmoLed", diffusedAtmoLed));
    pins.insert(std::pair<String, Pin*>("SplatteredAtmoLed", splatteredAtmoLed));

    // PCF 6 for LED
    Pin* pingPongModeLed = (Pin*) new Pcf8574Pin(0, OUTPUT, ledExpander4);
    Pin* dualEchoModeLed = (Pin*) new Pcf8574Pin(1, OUTPUT, ledExpander4);
    Pin* rhytmModeLed = (Pin*) new Pcf8574Pin(2, OUTPUT, ledExpander4);
    Pin* singleModeLed = (Pin*) new Pcf8574Pin(3, OUTPUT, ledExpander4);
    Pin* timeEcho1Led = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander4);
    Pin* noteEcho1Led = (Pin*) new Pcf8574Pin(5, OUTPUT, ledExpander4);
    Pin* timeEcho2Led = (Pin*) new Pcf8574Pin(6, OUTPUT, ledExpander4);
    Pin* noteEcho2Led = (Pin*) new Pcf8574Pin(7, OUTPUT, ledExpander4);

    pins.insert(std::pair<String, Pin*>("PingPongModeLed", pingPongModeLed));
    pins.insert(std::pair<String, Pin*>("DualEchoModeLed", dualEchoModeLed));
    pins.insert(std::pair<String, Pin*>("RhytmModeLed", rhytmModeLed));
    pins.insert(std::pair<String, Pin*>("SingleModeLed", singleModeLed));
    pins.insert(std::pair<String, Pin*>("TimeEcho1Led", timeEcho1Led));
    pins.insert(std::pair<String, Pin*>("NoteEcho1Led", noteEcho1Led));
    pins.insert(std::pair<String, Pin*>("TimeEcho2Led", timeEcho2Led));
    pins.insert(std::pair<String, Pin*>("NoteEcho2Led", noteEcho2Led));
}

PCF8574* PinFactory::getButtonExpander()
{
    return buttonExpander;
}

PCF8574* PinFactory::getButtonExpander2()
{
    return buttonExpander2;
}

Pin* PinFactory::get(String key)
{
    if(notInitialized()) {
        initialize();
    }

    auto search = pins.find(key);

    if(search == pins.end()) {
        // Very useful debug
        Serial.print("Pin not found! Name: ");
        Serial.println(key);
        delay(500);

        return nullptr;
    }

    return pins[key];
}

void PinFactory::runIntegratedCircuits()
{
    analogDigitalConverter->begin();

    buttonExpander->begin(0x38);
    buttonExpander2->begin(0x39);
    /*
    ledExpander->begin(0x3A);
    ledExpander2->begin(0x3B);
    ledExpander3->begin(0x3C);
    ledExpander4->begin(0x3D);
    */

    int i = 0;
    // apply modes for all pins
    for(auto iter = pins.begin(); (iter != pins.end()) || (i<35); iter++) {
        std::pair<String, Pin*> x = *iter; 
        x.second->applyMode();
        i++;
    }
}
