#include "motor.h"

void initMotors() {
    // set motor pins as outputs
    motor_en_l_ddr |= (1 << motor_en_l_num);
    motor_en_r_ddr |= (1 << motor_en_r_num);

    //turn off outputs
    motor_en_l_port &= ~(1 << motor_en_l_num);
    motor_en_r_port &= ~(1 << motor_en_r_num);
}

void homeAllAxis() {
    //home x
    while (!homeXPressed()) { moveMotor(X, BACKWARDS); }
    stopMotors();
    //home y
    while (!homeYPressed()) { moveMotor(Y, BACKWARDS); }
    stopMotors();
    //home z
    while (!minZPressed()) { moveMotor(Z, BACKWARDS); }
    stopMotors();
}

void moveMotor(enum motor id, enum motorDirection direction) {
    switch (id)
    {
    case X:
        selectMotorX();
        break;
    case Y:
        selectMotorY();
        break;
    case Z:
        selectMotorZ();
        break;
    default:
        stopMotors();
        break;
    }

    switch (direction)
    {
    case FORWARD:
        motor_en_l_port |= (1 << motor_en_l_num);
        motor_en_r_port &= ~(1 << motor_en_r_num);
        break;
    case BACKWARDS:
        motor_en_l_port &= ~(1 << motor_en_l_num);
        motor_en_r_port |= (1 << motor_en_r_num);
        break;
    default:
        stopMotors();
        break;
    }
}

void stopMotors() {
    motor_en_l_port |= (1 << motor_en_l_num);
    motor_en_r_port |= (1 << motor_en_r_num);
    motorsOff();
}

void moveXTo(char x_pos) {
    // move x until p amount of presses on x pos switch
    char curr_pos = 0;
    while (curr_pos <= x_pos) { 
        moveMotor(X, FORWARD); 
        if (posXPressed()) {
            curr_pos++;
        }
        _delay_ms(250);
    }

    stopMotors();
    
}

void moveYTo(char y_pos) {
    // move x until p amount of presses on x pos switch
    char curr_pos = 0;
    while (curr_pos <= y_pos) { 
        moveMotor(Y, FORWARD); 
        if (posYPressed()) {
            curr_pos++;
        }
        _delay_ms(500);
    }

    stopMotors();
}

void moveZUp() {
    while (!minZPressed()) { moveMotor(Z, BACKWARDS); }
    stopMotors();
}

void moveZDown() {
    moveMotor(Z, FORWARD);
    _delay_ms(motor_z_down_time);
    stopMotors();
}