#include <Arduino.h>
#include "Pins.h"
#include "Stepper.h"
#include "IR.h"
#include "myServo.h"
#include "LCD.h"
#include "PointsMode.h"
#include "Buttons.h"
#include "LiquidCrystal_I2C.h"
#include <vector>
Stepper stepper_1(STEP_PIN_1, DIR_PIN_1); //class for Steppers
Stepper stepper_2(STEP_PIN_2, DIR_PIN_2);

IR ir_1_1(IR_PIN1_1, IR_Pin1_1_BUFFER); //class for IR receivers
IR ir_1_2(IR_PIN1_2, IR_Pin1_2_BUFFER);
IR ir_1_3(IR_PIN1_3, IR_Pin1_3_BUFFER);
IR ir_1_4(IR_PIN1_4, IR_Pin1_4_BUFFER);
IR ir_2_1(IR_PIN2_1, IR_Pin2_1_BUFFER);
IR ir_2_2(IR_PIN2_2, IR_Pin2_2_BUFFER);

myServo servo_1_1(SERVO_PIN1_1); //class for servos
myServo servo_1_2(SERVO_PIN1_2);
myServo servo_1_3(SERVO_PIN1_3);
myServo servo_1_4(SERVO_PIN1_4);
myServo servo_2_1(SERVO_PIN2_1);
myServo servo_2_2(SERVO_PIN2_2);

Buttons modeButton(MODE_PIN); //buttons
Buttons startButton(START_PIN);

LCD myLCD; //LCD class wrapper

myServo ServoArray[6] = {servo_1_1, servo_1_2, servo_1_3, servo_1_4, servo_2_1, servo_2_2}; // Normal array for servos
IR IRArray[6] = {ir_1_1, ir_1_2, ir_1_3, ir_1_4, ir_2_1, ir_2_2}; // Normal array for IR receivers
Stepper StepperArray[2] = {stepper_1, stepper_2}; // Normal array for steppers


PointsMode pointsMode(IRArray, ServoArray, StepperArray, myLCD); //Points mode class



void limitSwitch1ISR() { //ISR for limit switches
    stepper_1.changeDir();
}
void limitSwitch2ISR() {
    stepper_2.changeDir();
}
void IR_1_1_ISR() { //ISR for IR receivers
    IR_Pin1_1_BUFFER = true;
}
void IR_1_2_ISR() {
    IR_Pin1_2_BUFFER = true;
}
void IR_1_3_ISR() {
    IR_Pin1_3_BUFFER = true;
}
void IR_1_4_ISR() {
    IR_Pin1_4_BUFFER = true;
}
void IR_2_1_ISR() {
    IR_Pin2_1_BUFFER = true;
}
void IR_2_2_ISR() {
    IR_Pin2_2_BUFFER = true;
}
void setup() {
    Serial.begin(9600); //for debugging
    pinMode(LIMIT_1, INPUT_PULLUP); //limit switches
    pinMode(LIMIT_2, INPUT_PULLUP);
    pinMode(IR_PIN1_1, INPUT); //IR receivers
    pinMode(IR_PIN1_2, INPUT);
    pinMode(IR_PIN1_3, INPUT);
    pinMode(IR_PIN1_4, INPUT);
    pinMode(IR_PIN2_1, INPUT);
    pinMode(IR_PIN2_2, INPUT);
    attachInterrupt(digitalPinToInterrupt(LIMIT_1), limitSwitch1ISR, FALLING); //ISRs
    attachInterrupt(digitalPinToInterrupt(LIMIT_2), limitSwitch2ISR, FALLING);
    attachInterrupt(digitalPinToInterrupt(IR_PIN1_1), IR_1_1_ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(IR_PIN1_2), IR_1_2_ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(IR_PIN1_3), IR_1_3_ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(IR_PIN1_4), IR_1_4_ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(IR_PIN2_1), IR_2_1_ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(IR_PIN2_2), IR_2_2_ISR, RISING);
}

void loop() {
// write your code here
}