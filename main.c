#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "display.h"
#include "relay.h"

int main(void) {
    initDisplay();
    initRelay();
    
    while(true) {
        selectMotorX();
        _delay_ms(500);
        selectMotorY();
        _delay_ms(500);
        selectMotorZ();
        _delay_ms(500);

        motorsOff();
        _delay_ms(500);

        magnetOn();
        _delay_ms(500);
        magnetOff();
        _delay_ms(500);
    }
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