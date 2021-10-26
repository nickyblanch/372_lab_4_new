#include "pwm.h"

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
 
    //set for non inverting timer

    TCCR3A |= (1<<COM3A1);
    TCCR3A &= ~(1<<COM3A0);
    




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

// set the duty cycle to 75%

OCR3C=600;

}