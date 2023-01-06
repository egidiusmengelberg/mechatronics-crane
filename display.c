#include "display.h"

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