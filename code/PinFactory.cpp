#include "PinFactory.h"

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
    // build
    Pin* pin = (Pin*) new ArduinoDigitalPin(5, OUTPUT);
    Pin* pin2 = (Pin*) new ArduinoAnalogPin(A5, INPUT);
    Pin* pin3 = (Pin*) new Mcp3008Pin(1, INPUT, analogDigitalConverter);
    //Pin* pin4 = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander, 0x3A);

    Pin* pin5 = (Pin*) new Pcf8574Pin(4, INPUT_PULLUP, buttonExpander);
    Pin* pin6 = (Pin*) new Pcf8574Pin(4, INPUT_PULLUP, buttonExpander2);

    Pin* interruptForPCF = (Pin*) new ArduinoDigitalPin(2, INPUT);

    // insert
    pins.insert(std::pair<String, Pin*>("pin", pin));
    pins.insert(std::pair<String, Pin*>("pin2", pin2));
    pins.insert(std::pair<String, Pin*>("pin3", pin3));
    //pins.insert(std::pair<String, Pin*>("pin4", pin4));
    pins.insert(std::pair<String, Pin*>("pin5", pin5));
    pins.insert(std::pair<String, Pin*>("pin6", pin6));

    pins.insert(std::pair<String, Pin*>("InterruptForPCF", interruptForPCF));
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

 /// apply modes for all pins
    // open pin 5 on PCF
    Pin* pin5 = get("pin5");
    pin5->applyMode();

    Pin* pin6 = get("pin6");
    pin6->applyMode();
}