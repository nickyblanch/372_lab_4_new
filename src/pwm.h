#ifndef PWM_H
#define PWM_H
#include <avr/io.h>
#include<Arduino.h>


void intiPWMTimer4();
void initPWMTimer3();
void changeDutyCycle(unsigned int adc_num);

#endif
