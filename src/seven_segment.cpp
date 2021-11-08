#include <avr/io.h>
#include "Arduino.h"

void initSevenSegment(){
DDRC |= (1<<DDC0) | (1<<DDC1) | (1<<DDC2) | (1<<DDC3) | (1<<DDC4) | (1<<DDC5) | (1<<DDC6);
}
void display_number(int num)	/* Function for displaying number (0-9) */
{
  switch(num)
  {
    case 0:
    PORTC |=(1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC |=(1<<PORTC3);
    PORTC |=(1<<PORTC4);
    PORTC |=(1<<PORTC5);
    PORTC &= ~ (1<<PORTC6);
    
    /* Drive disp_pin[0] to 0 */
	/* Driving 0 turns on LED segment for common anode display */
    break;

    case 1:
    PORTC &= ~(1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC &= ~ (1<<PORTC3);
    PORTC &= ~ (1<<PORTC4);
    PORTC &= ~ (1<<PORTC5);
    PORTC &= ~ (1<<PORTC6);

    /* Drive disp_pin[7] to 1 */
    /* Driving 1 turns off LED segment for common anode display */
    break;

    case 2:
    PORTC |=(1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC &= ~ (1<<PORTC2);
    PORTC |=(1<<PORTC3);
    PORTC |=(1<<PORTC4);
    PORTC &= ~ (1<<PORTC5);
    PORTC |=(1<<PORTC6);
    break;

    case 3:
    PORTC |=(1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC |=(1<<PORTC3);
    PORTC &= ~ (1<<PORTC4);
    PORTC &= ~ (1<<PORTC5);
    PORTC |=(1<<PORTC6);
    break;

    case 4:
    PORTC &= ~ (1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC &= ~ (1<<PORTC3);
    PORTC &= ~ (1<<PORTC4);
    PORTC |=(1<<PORTC5);
    PORTC |=(1<<PORTC6);
    break;

    case 5:
    PORTC |=(1<<PORTC0);
    PORTC &= ~ (1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC |=(1<<PORTC3);
    PORTC &= ~ (1<<PORTC4);
    PORTC |=(1<<PORTC5);
    PORTC |=(1<<PORTC6);

    break;
    case 6:
    PORTC |=(1<<PORTC0);
    PORTC &= ~ (1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC |=(1<<PORTC3);
    PORTC |=(1<<PORTC4);
    PORTC |=(1<<PORTC5);
    PORTC |=(1<<PORTC6);
    break;
    case 7:
    PORTC |=(1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC &= ~ (1<<PORTC3);
    PORTC &= ~ (1<<PORTC4);
    PORTC &= ~ (1<<PORTC5);
    PORTC &= ~ (1<<PORTC6);
    break;

    case 8:
    PORTC |=(1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC |=(1<<PORTC3);
    PORTC |=(1<<PORTC4);
    PORTC |=(1<<PORTC5);
    PORTC |=(1<<PORTC6);
    break;

    case 9:
    PORTC |=(1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC |=(1<<PORTC3);
    PORTC &= ~ (1<<PORTC4);
    PORTC |=(1<<PORTC5);
    PORTC |=(1<<PORTC6);
    break;
    default:
    PORTC &= ~ (1<<PORTC0);
    PORTC |=(1<<PORTC1);
    PORTC |=(1<<PORTC2);
    PORTC |=(1<<PORTC3);
    PORTC |=(1<<PORTC4);
    PORTC &= ~ (1<<PORTC5);
    PORTC |=(1<<PORTC6);
    break;
  }
}


