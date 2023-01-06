#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "display.h"

int main(void) {
    initDisplay();

    display(0,1,0);
    
    while(true) {}
}

// home axis
// wait for user input to select x pos
// wait for user input to select y pos
// wait for user input to start moving
// move x axis to pickup position
// move y axis to pickup position
// pickup using z axis
// move x axis to place position
// move y axis to place position
// drop down using z axis
// home axis