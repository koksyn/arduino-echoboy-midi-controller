#ifndef LCD_MANAGER_H
#define LCD_MANAGER_H

// library (working on Windows only) https://github.com/johnrickman/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>

class LcdManager {
private:
    static LiquidCrystal_I2C *lcd;
public:
    static void initialize();
    static void printFirstRow();
    static void printSecondRow();
    static void print(uint8_t  cos);
    static void print2(const String &s);
};

#endif
