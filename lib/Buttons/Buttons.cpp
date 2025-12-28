//
// Created by wikto on 28/12/2025.
//

#include "Buttons.h"

Buttons::Buttons(int p) : Pin(p), lastDebounceTime(0) {
    pinMode(Pin, INPUT_PULLUP); //init pin as input with pullup
}

bool Buttons::read() {
    if (digitalRead(Pin) == LOW) { //button pressed
        unsigned long currentTime = millis();
        if (currentTime - lastDebounceTime > debounceDelay) { //check debounce
            lastDebounceTime = currentTime;
            return true; //button press confirmed
        }
    }
}