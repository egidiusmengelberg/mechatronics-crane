enum displayChar {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    DASH,
    E,
    H,
    L,
    P,
    BLANK
};

void initDisplay();
void display(displayChar c, char pos, char dp);
void shiftOut(char val);