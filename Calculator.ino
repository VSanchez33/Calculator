#include "Keypad.h"
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display

String pad;
const byte numRows = 4;
const byte numCols = 4;
const int MAX_SIZE = 10;
int stack[MAX_SIZE];
int top = -1;

char keymap[numRows][numCols] =
{
  {'/', 'x', '-', '+'},
  {'=', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'}
};
byte rowPins[numRows] = {10,9, 8, 7};
byte colPins[numCols] = {6, 5, 4, 3};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols); //mapping keypad

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Calculator");
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
  char keypressed = myKeypad.getKey(); 
  String val = String(keypressed);
  pad += val;
  if (keypressed == '*'){
    pad = "";
    lcd.clear();
    lcd.print("Clear");
    delay(1000);
    pad = "";
    lcd.clear();
  }
  if (keypressed == '='){
    lcd.clear();
    pad = eval(pad);
  }
}

void push(int value){
  if (top < MAX_SIZE -1)
    stack[++top] = value;
}

int pop(){
  if (top >= 0)
    return stack[top--];
}

int eval(String expression) {
  int num1 = 0, num2 = 0, result = 0;
  char op = ' ';

  for (int i = 0; i < expression.length(); i++){
    char current = expression[i];

    if (isDigit(current)){  //convert char to int
      if (op == ' ') {
        num1 = num1 * 10 + (current - '0');
      } 
      else {
        num2 = num2 * 10 + (current - '0');
      }
    }
    else {
      op = current;
    }

    switch (op) {
      case '+':
        result = num1 + num2;
        break;
      case '-':
        result = num1 - num2;
        break;
      case 'x':
        result = num1 * num2;
        break;
      case '/':
        result = num1 / num2;
        break;
    }
  }
  return result;
}