# Calculator
A simple, physical calculator using an Arduino Uno

## Requirements
+ Arduino Uno
+ 4x4 Membrane keyboard for Arduino
+ I2C LCD
+ Various jumper cables

## Project Structure   
+ `Calculator.uno` - Code for reading and calculating imputs   
+ `Key.*` - Abstract definition of a key
+ `Keypad.*` - Interface to use the matrix keypad
+ `LiquidCrystal_I2C.*` - Driver for the I2C LCD

## Wiring
This project follows [this tutorial](https://miliohm.com/keypad-with-arduino-tutorial/) for all of it's wiring. The wiring diagram is also included below. 

![LCD and numpad wiring](https://i0.wp.com/miliohm.com/wp-content/uploads/2021/12/Schematic-keypad-with-LCD-scaled.jpg?resize=2048%2C1193&ssl=1)

## Use
The buttons work as follows:
+ Numbers - function as expected
+ A - addition   
+ B - subtraction   
+ C - multiplication   
+ D - division
+ \# - equals   
+ \* - clear   
