#include "PinFactory.h"

#include "ArduinoDigitalPin.h"
#include "ArduinoAnalogPin.h"
#include "Mcp3008Pin.h"
#include "Pcf8574Pin.h"

std::map<String, Pin*> PinFactory::pins;

Adafruit_MCP3008* PinFactory::analogDigitalConverter = new Adafruit_MCP3008();

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
    /*
    // initialize MCP3008 analog to digital converter
    analogDigitalConverter = new Adafruit_MCP3008();

    // initailize PCF8574 digital I/O expanders
    buttonExpander = new PCF8574();
    buttonExpander2 = new PCF8574();
    ledExpander = new PCF8574();
    ledExpander2 = new PCF8574();
    ledExpander3 = new PCF8574();
    ledExpander4 = new PCF8574();*/

    // run integrated circuits (caution: in case of wrong addresses program will stop working here)
    // these instructions have to be executed BEFORE Pin objects creation
    /*
    ledExpander->begin(0x3A);
    buttonExpander->begin(0x38);
    buttonExpander2->begin(0x39);
    ledExpander2->begin(0x3B);
    ledExpander3->begin(0x3C);
    ledExpander4->begin(0x3D);
    */

    // build
    Pin* pin = (Pin*) new ArduinoDigitalPin(5, OUTPUT);
    Pin* pin2 = (Pin*) new ArduinoAnalogPin(A5, INPUT);
    Pin* pin3 = (Pin*) new Mcp3008Pin(1, INPUT, analogDigitalConverter);
    //Pin* pin4 = (Pin*) new Pcf8574Pin(4, OUTPUT, ledExpander, 0x3A);
    Pin* pin5 = (Pin*) new Pcf8574Pin(4, INPUT_PULLUP, buttonExpander);

    // insert
    pins.insert(std::pair<String, Pin*>("pin", pin));
    pins.insert(std::pair<String, Pin*>("pin2", pin2));
    pins.insert(std::pair<String, Pin*>("pin3", pin3));
    //pins.insert(std::pair<String, Pin*>("pin4", pin4));
    pins.insert(std::pair<String, Pin*>("pin5", pin5));
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

void x() {
    Serial.println("Przerwanie");
}

void onExpanderInterrupt()
{
    Serial.println("Przerwanie na calym PCF");
    PinFactory::buttonExpander->checkForInterrupt();
}

void PinFactory::runIntegratedCircuits()
{
    analogDigitalConverter->begin();
    buttonExpander->begin(0x3A);

    // for interrupts! on arduino
    pinMode(2, INPUT);
    digitalWrite(2, HIGH);

    // for interrupts from whole PCF
    buttonExpander->enableInterrupt(2, onExpanderInterrupt);


    //Pin* pin4 = get("pin4");
    //pin4->applyMode();

    Pin* pin5 = get("pin5");
    pin5->applyMode();

    buttonExpander->attachInterrupt(4, x, FALLING);
}

/*
void Pcf8574Pin::attachInterrupt(void (*userFunc)(void), uint8_t interruptMode)
{
    expander->enableInterrupt(2, onExpanderInterrupt);
    expander->attachInterrupt(4, userFunc, interruptMode);
}*/