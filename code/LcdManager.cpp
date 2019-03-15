#include "LcdManager.h"

LiquidCrystal_I2C* LcdManager::lcd = new LiquidCrystal_I2C(0x27, CHARS_PER_LINE, 2);
uint8_t LcdManager::lineIndex = 0;
const char LcdManager::whitespace = ' ';
char LcdManager::topLine[CHARS_PER_LINE];
char LcdManager::bottomLine[CHARS_PER_LINE];

void LcdManager::initialize()
{
  lcd->init();
  lcd->backlight();
}

void LcdManager::render()
{
  lcd->clear();
  
  lcd->setCursor(0,0);
  lcd->print(topLine);
  lcd->setCursor(0,1);
  lcd->print(bottomLine);
}

void LcdManager::fillTopByWhitespaces()
{
  memset(topLine, whitespace, CHARS_PER_LINE);
}

void LcdManager::fillBottomByWhitespaces()
{
  memset(bottomLine, whitespace, CHARS_PER_LINE);
}

void LcdManager::clearTop()
{
  fillTopByWhitespaces();
  render();
}

void LcdManager::clearBottom()
{
  fillBottomByWhitespaces();
  render();
}

void LcdManager::clearAll()
{
  fillTopByWhitespaces();
  fillBottomByWhitespaces();
  render();
}

void LcdManager::printTop(uint8_t number)
{
  itoa(number, topLine, DECIMAL);
  render();
}

void LcdManager::printTop(const String &text)
{  
  strcpy(topLine, text.c_str()); 
  render();
}

void LcdManager::printBottom(uint8_t number)
{
  itoa(number, bottomLine, DECIMAL);
  render();
}

void LcdManager::printBottom(const String &text)
{
  strcpy(bottomLine, text.c_str());
  render();
}
