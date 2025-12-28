//
// Created by wikto on 27/12/2025.
//

#include "lcd.h"

LCD::LCD(){ //I2C address 0x27, 16 chars and 2 lines
    lcd.init();
    lcd.backlight();
    lcd.clear();
    mode = false;
    lcd.setCursor(0,0);
    lcd.print("Tryb gry: Punkty");
    lcd.setCursor(0,1);
    lcd.print("Naciśnij by zacząć");
    lcd.setCursor(0,2);
    lcd.print("High Score: ");
    lcd.print(highScore1);

}

void LCD::changeMode(bool mode) {
    this->mode = mode;
    lcd.clear();
    if(mode){
        lcd.setCursor(0,0);
        lcd.print("                    "); //clear previous score
        lcd.setCursor(0,0);
        lcd.print("Tryb gry: Punkty");
        lcd.setCursor(13,2);
        lcd.print("     "); //clear previous score
        lcd.setCursor(13,2);
        lcd.print(highScore1);
    } else{
        lcd.setCursor(0,0);
        lcd.print("                    "); //clear previous score
        lcd.setCursor(0,0);
        lcd.print("Tryb gry: Czas");
        lcd.setCursor(13,2);
        lcd.print("     "); //clear previous score
        lcd.setCursor(13,2);
        lcd.print(highScore2);
    }
}
void LCD::updateHighScore(int points) {
    if(mode){
        if(points <= highScore1){
            return;}
        highScore1 = points;
        lcd.setCursor(13,2);
        lcd.print("     "); //clear previous score
        lcd.setCursor(13,2);
        lcd.print(highScore1);
    } else{
        if(points <= highScore2){
            return;}
            highScore2 = points;
        lcd.setCursor(13,2);
        lcd.print("     "); //clear previous score
        lcd.setCursor(13,2);
        lcd.print(highScore2);
    }
}


void LCD::updateCurrentScore(int points) {
    currentScore= points;
    lcd.setCursor(13,1);
    lcd.print("     "); //clear previous score
    lcd.setCursor(13,1);
    lcd.print(points);
}
void LCD::start() {
    lcd.setCursor(0,0);
    lcd.print("                    "); //clear previous score
    lcd.setCursor(0,0);
    lcd.print("Gra zacznie się za:");
    lcd.setCursor(0,1);
    lcd.setCursor(0,2);
    lcd.print("                    "); //clear previous score
    lcd.setCursor(0,2);
    lcd.print("Powodzenia!");
    lcd.print("                    "); //clear previous score
    for(int i=3;i>0;i--){
        lcd.setCursor(10,1);
        lcd.print(i);
        delay(1000);
    }
}

void LCD::gameMode() {
    lcd.clear();
    currentScore = 0;
    lcd.setCursor(0,0);
    if(mode){
        lcd.print("Tryb Gry: Punkty");
    } else{
        lcd.print("Tryb Gry: Czas");
    }
    lcd.setCursor(0,1);
    lcd.print("Twój Wynik:");
    updateCurrentScore(currentScore);
    lcd.setCursor(0,2);
    lcd.print("High Score: ");
    if(mode){
        lcd.print(highScore1);
    } else{
        lcd.print(highScore2);
    }
}

void LCD::endScreen() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Koniec Gry!");
    lcd.setCursor(0,1);
    lcd.print("Twój Wynik:");
    updateCurrentScore(currentScore);
   if(mode){
        if(currentScore>=highScore1){
            lcd.setCursor(0,3);
            lcd.print("Nowy High Score!");
            highScore1=currentScore;
        }
        else{
            lcd.setCursor(0,3);
            lcd.print("Coś słabo poszło :(");
        }
    } else{
        if(currentScore>=highScore2){
            lcd.setCursor(0,3);
            lcd.print("Nowy High Score!");
            highScore2=currentScore;
        }
        else{
            lcd.setCursor(0,3);
            lcd.print("Coś słabo poszło :(");
        }
    }
    lcd.setCursor(0,3);
    lcd.print("High Score: ");
    if(mode){
        lcd.print(highScore1);
    } else{
        lcd.print(highScore2);
    }
}


