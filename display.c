#include "display.h"

// ones and tens per axis
char ox = 0;
char tx  = 0;
char oy = 0;
char ty  = 0;

void initDisplay() {
    display_din_ddr |= (1 << display_din_num);
    display_clk_ddr |= (1 << display_clk_num);
    display_cs_ddr |= (1 << display_cs_num);
    
    //shutdown register (0xXC) => 0x01 (normal operation)
    sendToDisplay(0x0C, 0x01);
    //Display-Test Register (0xXF) => 0x00 (normal operation)
    sendToDisplay(0x0F, 0x00);
    //Decode-Mode Register (0xX9) => 0xFF (Code B decode for digits 7–0)
    sendToDisplay(0x09, 0xFF);
    //Scan-Limit Register (0xXB) => 0x07 (Display digits 0 1 2 3 4 5 6 7)
    sendToDisplay(0x0B, 0x07);
    // Intensity Register (0xXA) => 0xX6 (13/32)
    sendToDisplay(0x0A, 0x06);

    //blank all segments
    for (char i = 0; i < 8; i++)
    {
        display(i, 0x0F, 0);
    }
    
}

void shiftOut(char val) {
    char i;

    for (i = 0; i < 8; i++)  {   
        if ((val & (1 << (7 - i)))) {
            display_din_port |= (1 << display_din_num);
        } else {
            display_din_port &= ~(1 << display_din_num);
        }
        //toggle clockPin
        display_clk_port |= (1 << display_clk_num);
        display_clk_port &= ~(1 << display_clk_num);      
    }
}

void sendToDisplay(char addr, char data) {
    shiftOut(addr);
    shiftOut(data);

    display_cs_port |= (1 << display_cs_num);
    display_cs_port &= ~(1 << display_cs_num);
}

void display(char seg, char val, bool dp) {
    char data = val | (dp << 7);
    sendToDisplay(seg+1, data);
}

void updateMenu(enum state *currentState, char* x_pos, char* y_pos, bool* axis_to_edit) {

    ox=*x_pos%10; 
    tx=(*x_pos/10)%10; 

    oy=*y_pos%10; 
    ty=(*y_pos/10)%10;

    //set x display
    display(4, ox, 0); 
    display(5, tx, 0);

    //set y display
    display(0, oy, 0); 
    display(1, ty, 0); 
    
    if (*axis_to_edit)
    {
        display(3, 0x0A, 0);
        display(7, 0x0F, 0);
    } else {
        display(3, 0x0F, 0);
        display(7, 0x0A, 0); 
    }

    if(upPressed()) {
        if (*axis_to_edit)
        {
            if (*y_pos + 1 > axis_y_max) {
                *y_pos = axis_y_min;
            } else {
                *y_pos = *y_pos + 1;
            }
        } else {
            if (*x_pos + 1 > axis_x_max) {
                *x_pos = axis_x_min;
            } else {
                *x_pos = *x_pos + 1;
            }
        }
        _delay_ms(ui_input_delay);
    }

    if(downPressed()) {
        if (*axis_to_edit)
        {
            if (*y_pos - 1 < axis_y_min) {
                *y_pos = axis_y_max;
            } else {
                *y_pos = *y_pos - 1;
            }
        } else {
            if (*x_pos - 1 < axis_x_min) {
                *x_pos = axis_x_max;
            } else {
                *x_pos = *x_pos - 1;
            }
        }
        _delay_ms(ui_input_delay);
    }

    if(selectPressed()) {
        *axis_to_edit = !*axis_to_edit;
        _delay_ms(ui_input_delay);
    }
}

void movingDisplay() {
    //all segments show line
    for (char i = 0; i < 8; i++)
    {
        display(i, 0x0A, 0);
    }
}