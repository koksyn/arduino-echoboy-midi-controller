#include "PinFactory.h"

#include "ArduinoDigitalPin.h"
#include "ArduinoAnalogPin.h"
#include "Mcp3008Pin.h"

std::map<String, Pin*> PinFactory::pins;

bool PinFactory::notInitialized()
{
    return pins.empty();
}

void PinFactory::initialize()
{
    // build
    Pin* pin = (Pin*) new ArduinoDigitalPin(5, OUTPUT);
    Pin* pin2 = (Pin*) new ArduinoAnalogPin(A5, INPUT);
    Pin* pin3 = (Pin*) new Mcp3008Pin(1, INPUT);

    // insert
    pins.insert(std::pair<String, Pin*>("pin", pin));
    pins.insert(std::pair<String, Pin*>("pin2", pin2));
    pins.insert(std::pair<String, Pin*>("pin3", pin3));
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
