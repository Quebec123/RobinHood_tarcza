//
// Created by wikto on 26/12/2025.
//

#ifndef ROBINHOOD_STEPPER_H
#define ROBINHOOD_STEPPER_H
#include <Arduino.h>

class Stepper {
    int stepPin;
    int dirPin;
    bool dir;
    bool isStopped;
public:
    Stepper(int stp, int dr);
    void changeDir();
    void move();
    void toggle();
    void stop();
};


#endif //ROBINHOOD_STEPPER_H
