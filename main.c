#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "display.h"
#include "relay.h"
#include "buttons.h"

// position to go to after start button is pressed
char x_pos = axis_x_min;
char y_pos = axis_y_min;

//what axis where currently editing with the menu (false=X, true=Y)
bool axis_to_edit = false;

int main(void) {
    initDisplay();
    initRelay();
    
    while(true) {
        updateMenu(&x_pos, &y_pos, &axis_to_edit);
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