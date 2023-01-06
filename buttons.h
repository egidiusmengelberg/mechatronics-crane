#ifndef BUTTONS_H
#define BUTTONS_H

#include <avr/io.h>
#include <stdbool.h>
#include "config.h"

void initButtons();

bool upPressed();
bool downPressed();
bool selectPressed();

#endif