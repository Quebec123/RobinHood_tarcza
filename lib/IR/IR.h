//
// Created by wikto on 26/12/2025.
//

#ifndef ROBINHOOD_IR_H
#define ROBINHOOD_IR_H
#include "Arduino.h"
#include "Pins.h"

class IR {
    int pin; //useless
    bool firstRead = true; //for the time measuring
    volatile bool &buffor; //reference to the buffor of the pin

public:
    IR(int p, volatile bool &b);
    int read();

};


#endif //ROBINHOOD_IR_H
