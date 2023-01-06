#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#include "buttons.h"
#include "config.h"

char ox;
char tx;
char oy;
char ty;

void initDisplay();
void shiftOut(char val);
void sendToDisplay(char addr, char data);
void display(char seg, char val, bool dp);
void updateMenu(char* x_pos, char* y_pos, bool* axis_to_edit);