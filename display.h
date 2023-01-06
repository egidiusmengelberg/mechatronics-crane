#include <avr/io.h>
#include <stdbool.h>
#include "config.h"

void initDisplay();
void shiftOut(char val);
void sendToDisplay(char addr, char data);
void display(char seg, char val, bool dp);