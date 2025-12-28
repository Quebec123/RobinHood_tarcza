//
// Created by wikto on 27/12/2025.
//

#ifndef ROBINHOOD_POINTSMODE_H
#define ROBINHOOD_POINTSMODE_H

#include <Arduino.h>
#include "Pins.h"
#include "Stepper.h"
#include "myServo.h"
#include "IR.h"
#include "LCD.h"
class PointsMode {
IR IRArray[6];
myServo ServoArray[6];
LCD lcd;
Stepper stepperArray[2];
int points;
unsigned long startTime;
unsigned long endTime;
int pickRandom();
public:
    PointsMode(IR irs[6], myServo servos[6], Stepper steppers[2], LCD lcd);
    void start();
};


#endif //ROBINHOOD_POINTSMODE_H
