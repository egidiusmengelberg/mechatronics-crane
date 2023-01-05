void initDisplay() {
    //datapin output
    //clockpin output
    //loadpin output

    //shutdown register (0xXC) => 0x01 (normal mode)
    // devoce mode (0xX9) => 0xFF (code B decode for digits 7-0)
}

void display(char c, char pos, char dp) {
    char data = c;
    
    if (dp) {
       data |= (1 << 7);  
    }

    shiftOut(pos);
    shiftOut(data);
    
    //toggle loadPin
}

void shiftOut(char val) {
    char i;

    for (i = 0; i < 8; i++)  {   
        //set datapin to !!(val & (1 << (7 - i)))
            
        //toggle clockPin      
    }
}