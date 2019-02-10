#ifndef PIN_FACTORY_H
#define PIN_FACTORY_H

#include <ArduinoSTL.h>
#include <map>
#include <Adafruit_MCP3008.h>
#include <PCF8574.h>

#include "Pin.h"

class PinFactory {
private:
    static std::map<String, Pin*> pins;

    static Adafruit_MCP3008* analogDigitalConverter;
    static PCF8574* buttonExpander;
    static PCF8574* buttonExpander2;
    static PCF8574* ledExpander;
    static PCF8574* ledExpander2;
    static PCF8574* ledExpander3;
    static PCF8574* ledExpander4;

    static bool notInitialized();
public:
    static void initialize();
    
    // exposed for interruption handling
    static PCF8574* getButtonExpander();
    static PCF8574* getButtonExpander2();

    static Pin* get(String key);
    static void runIntegratedCircuits();
};

#endif
