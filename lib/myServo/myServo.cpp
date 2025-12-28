//
// Created by wikto on 27/12/2025.
//

#include "myServo.h"

myServo::myServo(int p) : pin(p){
    servo.attach(pin);
}
void myServo::toggle() {
    if(isOn){
        servo.write(0);
        isOn = false;
    } else{
        servo.write(180);
        isOn = true;
    }
}
void myServo::on() {
    if (!isOn){
        servo.write(180);
        isOn = true;
    }
}
void myServo::off() {
    if (isOn){
        servo.write(0);
        isOn = false;
    }
}
bool myServo::getState() {
    return isOn;
}
