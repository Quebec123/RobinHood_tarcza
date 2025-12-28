//
// Created by wikto on 27/12/2025.
//

#include "LCD.h"

LCD::LCD() : LCD(0x27,20,4) { //I2C address 0x27, 16 chars and 2 lines
    LCD.init();
    LCD.backlight();
    LCD.clear();
    mode = false;
    LCD.setCursor(0,0);
    LCD.print("Tryb gry: Punkty");
    LCD.setCursor(0,1);
    LCD.print("Naciśnij by zacząć");
    LCD.setCursor(0,2);
    LCD.print("High Score: ");
    LCD.print(highScore1);

}

void LCD::changeMode(bool mode) {
    this->mode = mode;
    LCD.clear();
    if(mode){
        LCD.setCursor(0,0);
        LCD.print("                    "); //clear previous score
        LCD.setCursor(0,0);
        LCD.print("Tryb gry: Punkty");
        LCD.setCursor(13,2);
        LCD.print("     "); //clear previous score
        LCD.setCursor(13,2);
        LCD.print(highScore1);
    } else{
        LCD.setCursor(0,0);
        LCD.print("                    "); //clear previous score
        LCD.setCursor(0,0);
        LCD.print("Tryb gry: Czas");
        LCD.setCursor(13,2);
        LCD.print("     "); //clear previous score
        LCD.setCursor(13,2);
        LCD.print(highScore2);
    }
}
void LCD::updateHighScore(int points) {
    if(mode)
        if(points <= highScore1){
            return;}
        highScore1 = points;
        LCD.setCursor(13,2);
        LCD.print("     "); //clear previous score
        LCD.setCursor(13,2);
        LCD.print(highScore1);
    } else{
        if(points <= highScore2){
            return;}
            highScore2 = points;
        LCD.setCursor(13,2);
        LCD.print("     "); //clear previous score
        LCD.setCursor(13,2);
        LCD.print(highScore2);
    }
}

void LCD::updateCurrentScore(int points) {
    currentScore= points;
    LCD.setCursor(13,1);
    LCD.print("     "); //clear previous score
    LCD.setCursor(13,1);
    LCD.print(points);
}
void LCD::start() {
    LCD.setCursor(0,0);
    LCD.print("                    "); //clear previous score
    LCD.setCursor(0,0);
    LCD.print("Gra zacznie się za:");
    LCD.setCursor(0,1);
    LCD.setCursor(0,2);
    LCD.print("                    "); //clear previous score
    LCD.setCursor(0,2);
    LCD.print("Powodzenia!");
    LCD.print("                    "); //clear previous score
    for(int i=3;i>0;i--){
        LCD.setCursor(10,1);
        LCD.print(i);
        delay(1000);
    }
}

void LCD::gameMode() {
    LCD.clear();
    currentScore = 0;
    LCD.setCursor(0,0);
    if(mode){
        LCD.print("Tryb Gry: Punkty");
    } else{
        LCD.print("Tryb Gry: Czas");
    }
    LCD.setCursor(0,1);
    LCD.print("Twój Wynik:");
    updateCurrentScore(currentScore);
    LCD.setCursor(0,2);
    LCD.print("High Score: ");
    if(mode){
        LCD.print(highScore1);
    } else{
        LCD.print(highScore2);
    }
}

void LCD::endScreen() {
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("Koniec Gry!");
    LCD.setCursor(0,1);
    LCD.print("Twój Wynik:");
    updateCurrentScore(currentScore);
   if(mode){
        if(currentScore>=highScore1){
            LCD.setCursor(0,3);
            LCD.print("Nowy High Score!");
            highScore1=currentScore;
        }
        else{
            LCD.setCursor(0,3);
            LCD.print("Coś słabo poszło :(");
        }
    } else{
        if(currentScore>=highScore2){
            LCD.setCursor(0,3);
            LCD.print("Nowy High Score!");
            highScore2=currentScore;
        }
        else{
            LCD.setCursor(0,3);
            LCD.print("Coś słabo poszło :(");
        }
    }
    LCD.setCursor(0,3);
    LCD.print("High Score: ");
    if(mode){
        LCD.print(highScore1);
    } else{
        LCD.print(highScore2);
    }
}


