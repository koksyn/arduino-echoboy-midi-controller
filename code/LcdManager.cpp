#include "LcdManager.h"

hd44780_I2Cexp* LcdManager::lcd = new hd44780_I2Cexp();

void LcdManager::initialize()
{
    // initialize LCD with number of columns and rows
    lcd->begin(20, 4);
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
