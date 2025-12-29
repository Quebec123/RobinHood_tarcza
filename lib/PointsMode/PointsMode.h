#ifndef ROBINHOOD_POINTSMODE_H
#define ROBINHOOD_POINTSMODE_H

#include <Arduino.h>
#include "Pins.h"
#include "Stepper.h"
#include "myServo.h"
#include "IR.h"
#include "LCD.h"

class PointsMode {
    IR* IRArray; // Pointer to IR array
    myServo* ServoArray; // Pointer to Servo array
    Stepper* StepperArray; // Pointer to Stepper array
    LCD lcd;
    int points;
    unsigned long startTime = 0;
    unsigned long endTime = 0;
    int pickRandom();
public:
    PointsMode(IR IRARR[], myServo SERVOARR[], Stepper STEPPERARR[], LCD &newlcd);
    void start();
};

#endif //ROBINHOOD_POINTSMODE_H