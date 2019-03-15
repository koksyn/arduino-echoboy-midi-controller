#ifndef LCD_MANAGER_H
#define LCD_MANAGER_H

// library (working on Windows only) https://github.com/johnrickman/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>

#define DECIMAL 10
#define CHARS_PER_LINE 16

class LcdManager {
private:
    static LiquidCrystal_I2C *lcd;

    static uint8_t lineIndex;
    static const char whitespace;
    static char topLine[CHARS_PER_LINE];
    static char bottomLine[CHARS_PER_LINE];

    static void render();
    static void fillTopByWhitespaces();
    static void fillBottomByWhitespaces();
public:
    static void initialize();
    static void clearTop();
    static void clearBottom();
    static void clearAll();
    
    // first LCD line
    static void printTop(uint8_t number);
    static void printTop(const String &text);

    // second LCD line
    static void printBottom(uint8_t number);
    static void printBottom(const String &text);
};

#endif
