// Author: Nicolas Blanchard
// Net ID: nickyblanch
// Date: 10/25/21
// Assignment:     Lab 4
//
// Description: 
//
// Requirements: check 'Lab 4 Requirements.pdf'

//----------------------------------------------------------------------//
// Libraries and source files

#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "switch.h"
#include "timer.h"
#include "pwm.h"
#include "adc.h"
#include "seven_segment.h"

//----------------------------------------------------------------------//
// Global variables

//----------------------------------------------------------------------//
// State machines

/*
 * Define a set of states that can be used in the state machine using an enum.
 */
typedef enum stateEnum {wait_press, debounce_press, wait_release, debounce_release} stateEnum;

// Initialize states. Remember to use volatile
volatile stateEnum button_state = wait_press; // ASSUMING WE BEGIN IN A STATE WHERE THE BUTTON IS NOT BEING PRESSED

//----------------------------------------------------------------------//
// Main function
int main(void) {
  unsigned int result = 0;

  while(1){

    // Check the state
    switch(button_state) {
      case wait_press:
        // Do nothing; we are waiting for the button to be pressed.
        break;
      case debounce_press:
        // Wait for the noisy 'debounce' state to pass. Then, we are awaiting release.
        delayMs(1);
        button_state = wait_release;
        break;
      case wait_release:
        // Do nothing; we are waiting for the button to be released.
        break;
      case debounce_release:
        // The button has been released.
        // Disable the button interrupt.


        for (int i = 0; i < 10; i++) {
          // TODO: Send i to seven segment display
          delayMs(1000);
        }

        // Enable the button interrupt

        // Wait for the noisy 'debounce' state to pass. Then, we are awaiting press.
        delayMs(1);
        button_state = wait_press;
        break;
    }

    
    // read in ADCL first then read ADCH
    result = ADCL;
    result += ((unsigned int) ADCH) << 8;
    Serial.println(result);
  }

}

//----------------------------------------------------------------------//
// Interrupt

ISR (PCINT0_vect) {
  // When the interrupt flag is triggered:

  if (button_state == wait_press) {
    // The button was pushed while we were waiting for it to be pressed. Enter the first debounce state.
    button_state = debounce_press;
  }
  else if (button_state == wait_release) {
    // The button was released while we were waiting for it to be released. Enter the second debounce state.
    button_state = debounce_release;
    
    // TODO
    
  }
  // If the flag triggers while the button is 1 in one of the noisy debounce states, we do nothing.
}

