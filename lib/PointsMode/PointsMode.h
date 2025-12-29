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
#include "array"
class PointsMode {
    IR* IRArray[6];
    myServo* ServoArray[6];
    LCD* lcd;
    Stepper* StepperArray[2];
int points;
unsigned long startTime =0;
unsigned long endTime =0;
int pickRandom();
public:
    PointsMode(IR *IRARR[6], myServo *SERVOARR[6], Stepper *STEPPERARR[2],LCD *newlcd);
    void start();
};


#endif //ROBINHOOD_POINTSMODE_H
