#include "pwm.h"

// !!
// TODO:
// This code appears to be a ash-up of code for two different PWM modes: 10 bit fast, as well as the variable frequency mode.
// Pretty sure we should only be changing the values in OCR4A and OCR3A (to control duty cycle), not OCR4C and OCR3C.
// I'll look into it more tomorrow

//copy pasted code from class
void initPWMTimer4() {
    //set data direction pins
    DDRB |= (1<<PORTH3);
    DDRB |= (1<< PORTB7);
 
    //set for non inverting timer

    TCCR4A |= (1<<COM4A1);
    TCCR4A &= ~(1<<COM4A0);
    




    //set the mode for the timer for  fast PWM 10 BIT
    TCCR4A |= (1<<WGM41);
    TCCR4A |= (1<<WGM40);
    TCCR4B |= (1<<WGM42);
    TCCR4B &= (1<< WGM43);
    //set prescaler to 1
    TCCR4B|= (1<<CS40);
    TCCR4B &= ~(1<<CS41);
    TCCR4B &= ~(1<<CS42);



//initialize the output compare register to ****
OCR4A =251;

// set the duty cycle to 75%

OCR4C=600;

}



void initPWMTimer3() {
    //set data direction pins
    DDRB |= (1<<PORTE3);
    DDRB |= (1<< PORTB7);
 
    //set for inverting timer

    TCCR3A |= (1<<COM3A0);
    TCCR3A &= ~(1<<COM3A1);
    




    //set the mode for the timer for  fast PWM 10 BIT
    TCCR3A |= (1<<WGM31);
    TCCR3A |= (1<<WGM30);
    TCCR3B |= (1<<WGM32);
    TCCR3B &= (1<< WGM33);
    //set prescaler to 1
    TCCR3B|= (1<<CS30);
    TCCR3B &= ~(1<<CS31);
    TCCR3B &= ~(1<<CS32);



//initialize the output compare register to ****
OCR3A =251;



}
void changeDutyCycle(unsigned int adc){
OCR3A=adc;
OCR4A=adc;

}



void changeDutyCycle(unsigned short int adc_num) {
    // INPUT: adc_num, a 16 bit number that contains the 10-bit combination of ADCH and ADCL registers.
    // GOAL: Edit the OCRnA registers for the two 10-bit PWM timers, so that we get the correct
    // speed and direction on the DC motor.

    // FIRST SCENARIO: WE ARE GOING CLOCKWISE (USE PWM ON TIMER 3)
    if (adc_num < 512) {
        // 0 represents max ramp (100% duty cycle,) and 512 represents min rmp (0% duty cycle)
        OCR3A |= (1 << (0b1111111111 - adc_num));
    }
    // SECOND SCENARIO: WE ARE GOING CLOCKWISE (USE PWM ON TIMER 3)
    else if (adc_num > 512) {
        // 0 represents max ramp (100% duty cycle,) and 512 represents min rmp (0% duty cycle)
        OCR4A |= (1 << (adc_num));
    }
    // THIRD SCENARIO: WE ARE NOT MOVING THE MOTOR
    else {
        OCR3A |= (0);
    }

}