#ifndef DISPLAY_H
#define DISPLAY_H

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#include "config.h"
#include "buttons.h"

char ox;
char tx;
char oy;
char ty;

void initDisplay();
void shiftOut(char val);
void sendToDisplay(char addr, char data);
void display(char seg, char val, bool dp);
void updateMenu(enum state *currentState, char* x_pos, char* y_pos, bool* axis_to_edit);
void movingDisplay();
void errorDisplay();
void clearDisplay();


#endif