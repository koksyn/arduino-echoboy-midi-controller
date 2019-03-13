#include "LcdManager.h"

hd44780_I2Cexp* LcdManager::lcd;

void LcdManager::initialize(hd44780_I2Cexp* lcdInstance)
{
    lcd = lcdInstance;

    // initialize LCD with number of columns and rows
    lcd->begin(16, 2);
}

void LcdManager::printFirstRow()
{
    lcd->home();
    lcd->print(1);
}

void LcdManager::printSecondRow()
{
    lcd->setCursor(0, 1);
    lcd->print(2);
}
