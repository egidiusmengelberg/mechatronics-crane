#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "display.h"
#include "relay.h"
#include "buttons.h"
#include "config.h"

enum state currentState = INIT;

// position to go to after start button is pressed
char x_pos = axis_x_min;
char y_pos = axis_y_min;

//what axis where currently editing with the menu (false=X, true=Y)
bool axis_to_edit = false;

int main(void) {

    while(true) {

        switch (currentState)
        {
        case INIT:
            initRelay();
            initButtons();
            initDisplay();
            currentState = HOMING;
            break;

        case HOMING:
            //homeAllAxis();
            currentState = MENU;
            break;
        
        case MENU:
            updateMenu(&currentState, &x_pos, &y_pos, &axis_to_edit);
            break;

        case MOVING:
            movingDisplay();
            //make machine move
            currentState = HOMING;
            break;

        default:
            break;
        }
    }
}