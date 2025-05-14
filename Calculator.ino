/*Keypad example
    by miliohm.com */

#include "Keypad.h"
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display

String pad;
const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] =
{
  {'D', 'C', 'B', 'A'},
  {'#', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'}
};
//------------------------------------------------------------
byte rowPins[numRows] = {10,9, 8, 7};
byte colPins[numCols] = {6, 5, 4, 3};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols); //mapping keypad

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Keypad");
  lcd.setCursor(0, 1);
  lcd.print("Test");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  readKeypad();
  lcd.setCursor(0, 0);
  lcd.print(pad);
  delay(100);
}

void readKeypad() {
  char keypressed = myKeypad.getKey(); //deteksi penekanan keypad
  String konv = String(keypressed);
  pad += konv;
}