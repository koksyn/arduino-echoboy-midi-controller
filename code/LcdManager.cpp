#include "LcdManager.h"

LiquidCrystal_I2C* LcdManager::lcd = new LiquidCrystal_I2C(0x27,16,2);

void LcdManager::initialize()
{
  lcd->init();
  lcd->backlight();
}

void LcdManager::printFirstRow()
{
  lcd->setCursor(0,0);
  lcd->print(987654321);
}

void LcdManager::printSecondRow()
{
  lcd->setCursor(0,1);
  lcd->print(1234123);
}

void LcdManager::print(uint8_t cos)
{
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print(cos);
}

void LcdManager::print2(const String &s)
{
  lcd->setCursor(0,1);
  lcd->print(s);
}
