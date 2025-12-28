//
// Created by wikto on 27/12/2025.
//

#ifndef ROBINHOOD_LCD_H
#define ROBINHOOD_LCD_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
class LCD {
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
bool mode=false; //false = time mode, true = points mode
int highScore1=0;
int highScore2=0;
int currentScore=0;
public:
    LCD();
    void changeMode(bool mode);
    void updateHighScore(int points);
    void updateCurrentScore(int points);
    void start();
    void endScreen();
    void gameMode();

};


#endif //ROBINHOOD_LCD_H
