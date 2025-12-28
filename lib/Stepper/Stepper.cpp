//
// Created by wikto on 26/12/2025.
//

#include "Stepper.h"

Stepper::Stepper(int stp, int dr) : stepPin(stp), dirPin(dr), dir(true), isStopped(false) {
    pinMode(stepPin, OUTPUT); //init pins as output
    pinMode(dirPin, OUTPUT);
}
void Stepper::changeDir() {
    dir = !dir; //I change the direction variable
    digitalWrite(stepPin, LOW); // stop for safety
    digitalWrite(dirPin, dir); //set the direction pin to the new direction
    analogWrite(stepPin, 128); //write a nice PWM to quickly move the stepper
}
void Stepper::move() {
    if (!isStopped) { //if im not stopped currently
        analogWrite(stepPin, 128); //write a nice PWM to quickly move the stepper
        isStopped = false; //make sure to reset the flag
    }
}
void Stepper::stop() {
    isStopped = true; //set the flag
    digitalWrite(stepPin, LOW); // 0 PWM signal to stop
}
void Stepper::toggle() {
    if (isStopped) {
        move();
        isStopped = false;
    } else {
        stop();
        isStopped = true;
    }
}