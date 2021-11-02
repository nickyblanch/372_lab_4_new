#ifndef PWM_H
#define PWM_H
#include <avr/io.h>
#include<Arduino.h>


void initPWMTimer4();
void initPWMTimer3();
void changeDutyCycle(unsigned short int adc_num);

#endif
