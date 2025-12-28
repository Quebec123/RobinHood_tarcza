//
// Created by wikto on 27/12/2025.
//

#include "PointsMode.h"

PointsMode::PointsMode(IR irs[6], myServo servos[6], Stepper steppers[2], LCD lcd) : IRArray{irs[0], irs[1], irs[2], irs[3], irs[4], irs[5]},
                                                                                      ServoArray{servos[0], servos[1], servos[2], servos[3], servos[4], servos[5]},
                                                                                      stepperArray{steppers[0], steppers[1]},
                                                                                      lcd(lcd),
                                                                                      points(0) {
}
int PointsMode::pickRandom() {
    int index = random(0, 6); //pick a random index from 0 to 5
    return index;
}

void PointsMode::start() { //zaczynam grę
    points = 0; //ustawaim punkty
    int current=0; //inicjalizacja dla random punktów
    lcd.start(); //zliczam w dół
    startTime = millis(); //pamiętam o której gra się zaczęła
    unsigned long gameDuration = 60000; //1 minute
    while (millis() - startTime < gameDuration) { //gra trwa minutę
        current = pickRandom(); //wybieram losowy punkt
        if(current < 4){ //zatrzymuję banasia
            stepperArray[0].toggle();
        } else{
            stepperArray[1].toggle();
        }
        ServoArray[current].on(); //podnoszę cel

        while (!IRArray[current].read()) { //czekam na strzał
            if (millis() - startTime >= gameDuration) { //sprawdzam by nie przekroczył czasu
                break; // gdy przekroczył wychodzę z pętli
            }
            points++; //dodaję punkty gdy trafi
        }
        ServoArray[current].off();//wyłączam cel
        if(current < 4){ //uruchamiam banasia
            stepperArray[0].toggle();
        } else{
            stepperArray[1].toggle();
        }
        lcd.updateCurrentScore(points); //aktualizacja wyniku
    }
    lcd.endScreen(); //koniec gry na ekranie
    lcd.updateHighScore(points);//może mu się udało zbić high score
}