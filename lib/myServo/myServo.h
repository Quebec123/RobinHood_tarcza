//
// Created by wikto on 27/12/2025.
//

#ifndef ROBINHOOD_MYSERVO_H
#define ROBINHOOD_MYSERVO_H
#include "Arduino.h"
#include "Pins.h"
#include "ESP32Servo.h"


class myServo {
    Servo servo;
    int pin;
    bool isOn = false;
public:
    myServo(int p);
    void toggle();
    void on();
    void off();
    bool getState();
};


#endif //ROBINHOOD_MYSERVO_H
