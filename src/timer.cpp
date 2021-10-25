#include "timer.h"



//copy pasted code from class
void initPWMTimer4() {
    //set data direction pins
    DDRB |= (1<<PORTB5);
    DDRB |= (1<< PORTB7);
 
    //set for non inverting timer

    TCCR4A |= (1<<COM1A1);
    TCCR4A &= ~(1<<COM1A0);
    





    //set the mode for the timer for  fast PWM 10 BIT
    TCCR4A |= (1<<WGM11);
    TCCR4A |= (1<<WGM10);
    TCCR4B |= (1<<WGM12);
    TCCR4B &= (1<< WGM13);
    //set prescaler to 1
    TCCR4B|= (1<<CS10);
    TCCR4B &= ~(1<<CS11);
    TCCR4B &= ~(1<<CS12);



//set the 
OCR4A =1999;

// set the duty cycle to 75%

OCR4C=600;

}