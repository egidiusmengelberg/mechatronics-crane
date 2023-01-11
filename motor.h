#ifndef MOTOR_H
#define MOTOR_H

#include "relay.h"
#include "config.h"
#include "buttons.h"

//motors as output, relays as output
void initMotors();

void homeAllAxis();

void moveMotor(enum motor id, enum motorDirection direction);
void stopMotors();

void moveXTo(char p);

void moveYTo(char p);

void moveZUp();
void moveZDown();

#endif