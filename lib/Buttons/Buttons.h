//
// Created by wikto on 28/12/2025.
//

#ifndef ROBINHOOD_BUTTONS_H
#define ROBINHOOD_BUTTONS_H
#include <Arduino.h>

class Buttons {
int Pin;
unsigned long lastDebounceTime;
const unsigned long debounceDelay = 50; //50 ms debounce time
public:
    Buttons(int p);
    bool read();
};


#endif //ROBINHOOD_BUTTONS_H
