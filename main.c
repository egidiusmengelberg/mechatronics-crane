#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "display.h"
//#include "relay.h"
#include "buttons.h"

// position to go to after start button is pressed
char x_pos = axis_x_min;
char y_pos = axis_y_min;

// ones and tens per axis
char ox = 0;
char tx  = 0;
char oy = 0;
char ty  = 0;

//what axis where currently editing with the menu (false=X, true=Y)
bool axis_to_edit = false;

void updateMenu() {
    ox=x_pos%10; 
    tx=(x_pos/10)%10; 

    oy=y_pos%10; 
    ty=(y_pos/10)%10;

    //set x display
    display(4, ox, 0); 
    display(5, tx, 0);

    //set y display
    display(0, oy, 0); 
    display(1, ty, 0); 
    
    if (axis_to_edit)
    {
        display(3, 0x0A, 0);
        display(7, 0x0F, 0);
    } else {
        display(3, 0x0F, 0);
        display(7, 0x0A, 0); 
    }
    

    if(upPressed()) {
        if (axis_to_edit)
        {
            if (y_pos + 1 > axis_y_max) {
                y_pos = axis_y_min;
            } else {
                y_pos++;
            }
        } else {
            if (x_pos + 1 > axis_x_max) {
                x_pos = axis_x_min;
            } else {
                x_pos++;
            }
        }
        _delay_ms(ui_input_delay);
    }

    if(downPressed()) {
        if (axis_to_edit)
        {
            if (y_pos - 1 < axis_y_min) {
                y_pos = axis_y_max;
            } else {
                y_pos--;
            }
        } else {
            if (x_pos - 1 < axis_x_min) {
                x_pos = axis_x_max;
            } else {
                x_pos--;
            }
        }
        _delay_ms(ui_input_delay);
    }

    if(selectPressed()) {
        axis_to_edit = !axis_to_edit;
        _delay_ms(ui_input_delay);
    }
}

int main(void) {
    initDisplay();
    //initRelay();
    
    while(true) {
        updateMenu();
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