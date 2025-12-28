//
// Created by wikto on 26/12/2025.
//

#ifndef ROBINHOOD_PINS_H
#define ROBINHOOD_PINS_H
const int STEP_PIN_1 = 42; //limit pins for the 1st driver
const int DIR_PIN_1 = 41;
const int LIMIT_1 = 18;

const int IR_PIN1_1 = 4; //IR pins and their respectible buffors for ISR
inline volatile bool IR_Pin1_1_BUFFER = 0;
const int IR_PIN1_2 = 5;
inline volatile bool IR_Pin1_2_BUFFER = 0;
const int IR_PIN1_3 = 6;
inline  bool IR_Pin1_3_BUFFER = 0;
const int IR_PIN1_4 = 7;
inline volatile bool IR_Pin1_4_BUFFER = 0;

const int SERVO_PIN1_1 = 12; //Servo pins
const int SERVO_PIN1_2 = 13;
const int SERVO_PIN1_3 = 14; //Servo pins
const int SERVO_PIN1_4 = 15;
//----------------------------------------------------------//
const int STEP_PIN_2 = 40;
const int DIR_PIN_2 = 39;
const int LIMIT_2 = 35;

const int IR_PIN2_1 = 10;
inline volatile bool IR_Pin2_1_BUFFER = 0;
const int IR_PIN2_2 = 11;
inline volatile bool IR_Pin2_2_BUFFER = 0;

const int SERVO_PIN2_1 = 16; //Servo pins
const int SERVO_PIN2_2 = 17;

//----------------------------------------------------------//

const int MODE_PIN = 2;
const int START_PIN = 1;

const int LCD_SDA = 8;
const int LCD_SCL = 9;

#endif //ROBINHOOD_PINS_H
