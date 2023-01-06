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