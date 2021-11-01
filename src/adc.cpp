
#include "adc.h"

//new adc file
void initADC7(){

    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);
    ADMUX &=~(1<<ADLAR);

    ADMUX |= (1<<MUX2)| (1<<MUX1)|(1<<MUX0);
    ADMUX &= ~(1<<MUX4) ;
    ADMUX &= ~(1<<MUX3) ;
    ADCSRB &= ~(1<<MUX5);

      ADCSRB &= ~((1<< ADTS2)|(1<<ADTS1) | (1<<ADTS0));

    //ENABLE ADC AND AUTO TRIGGERING
    ADCSRA |= ((1<<ADEN)|(1<<ADATE));

    ADCSRA |= (1<<ADPS2) |(1<<ADPS1) |(1<<ADPS0) ;

    DIDR0 |= (1<< ADC7D);

    //START FIRST ADC CONVERSTION

    ADCSRA|= (1<<ADSC);
    







}