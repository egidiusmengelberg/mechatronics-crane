#ifndef RELAY_H
#define RELAY_H

#include <avr/io.h>
#include <stdbool.h>

#include "config.h"

void initRelay();

void selectMotorX();
void selectMotorY();
void selectMotorZ();

void motorsOff();

void magnetOn();
void magnetOff();

#endif