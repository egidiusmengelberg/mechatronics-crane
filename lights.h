#ifndef LIGHTS_H
#define LIGHTS_H

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "config.h"

void initLights(void);
void lightsOn(void);
void lightsOff(void);

#endif