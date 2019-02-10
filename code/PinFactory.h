#ifndef PIN_FACTORY_H
#define PIN_FACTORY_H

#include <ArduinoSTL.h>
#include <map>
#include "Pin.h"

class PinFactory {
private:
    static std::map<String, Pin*> pins;
    static bool notInitialized();
    static void initialize();
public:
    static Pin* get(String key);
};

#endif
