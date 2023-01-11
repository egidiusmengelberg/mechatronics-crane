#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "relay.h"
#include "motor.h"
#include "config.h"
#include "display.h"
#include "buttons.h"

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
        // init machine
        case INIT:
            initRelay();
            initMotors();
            initButtons();
            initDisplay();
            currentState = HOMING;
            break;
        // home machine
        case HOMING:
            homeAllAxis();
            currentState = MENU;
            break;
        // show menu
        case MENU:
            updateMenu(&currentState, &x_pos, &y_pos, &axis_to_edit);
            break;
        // pick and place
        case MOVING:
            movingDisplay();
            
            //make machine move
            moveXTo(x_pickup_position);
            moveYTo(y_pickup_position);
            moveZDown();
            magnetOn();
            moveZUp();
            moveXTo(x_pos - 1);
            moveYTo(y_pos - 1);
            moveZDown();
            magnetOff();
            moveZUp();

            //reset position variables
            x_pos = axis_x_min;
            y_pos = axis_y_min;

            clearDisplay(); 

            currentState = HOMING;
            break;
        // oh dear, something went terribly wrong, this should not be possible
        default:
            //draw error display every second
            errorDisplay();
            _delay_ms(1000);
            break;
        }
    }
}