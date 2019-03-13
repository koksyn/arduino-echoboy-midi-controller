#ifndef LCD_MANAGER_H
#define LCD_MANAGER_H

// https://github.com/duinoWitchery/hd44780

#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

class LcdManager {
private:
    static hd44780_I2Cexp *lcd;
public:
    static void initialize(hd44780_I2Cexp* lcdInstance);
    static void printFirstRow();
    static void printSecondRow();
};

#endif
