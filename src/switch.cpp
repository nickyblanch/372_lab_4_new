// Author: Nicolas Blanchard,
// Net ID: nickyblanch,
// Date: 10/25/21
// Assignment: Lab 4
// Description: This file implements the initialization of an external
//              switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPD0(){

    // Initialize PD0 (pin 21) for input (set DDR to input). Enable pullup resistor.
    // NOTE: To set the port to input, we must 'clear' the bit by setting it to zero
    // while simultaneously preserving the other bits in the DDR register.

    DDRB &= ~( 1 << DDD0);  // Clear the bit in DDRD0
    PORTB |= (1 << PORTD0); // Enable pullup resistor by writing 1 to the port.

    // Pin-Change Interrupts must be enabled for pin PD0
    PCICR |= (1 << PCIE0);   // Enable PCINT for 0-7
    PCMSK0 |= (1 << PCINT3); // Enable PCINT3 specifically in the pin change mask register 0
}
