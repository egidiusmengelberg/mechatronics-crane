#include "relay.h"

void initRelay() {
    //set relay ports as output
    relay_x_ddr |= (1 << relay_x_num);
    relay_y_ddr |= (1 << relay_y_num);
    relay_z_ddr |= (1 << relay_z_num);
    relay_magnet_ddr |= (1 << relay_magnet_num);

    motorsOff();
    magnetOff();
}

void selectMotorX() {
    motorsOff();
    relay_x_port &= ~(1 << relay_x_num);
}

void selectMotorY() {
    motorsOff();
    relay_y_port &= ~(1 << relay_y_num);
}

void selectMotorZ() {
    motorsOff();
    relay_z_port &= ~(1 << relay_z_num);
}

void motorsOff() {
    relay_x_port |= (1 << relay_x_num);
    relay_y_port |= (1 << relay_y_num);
    relay_z_port |= (1 << relay_z_num);
}

void magnetOn() {
    relay_magnet_port &= ~(1 << relay_magnet_num);

}

void magnetOff() {
    relay_magnet_port |= (1 << relay_magnet_num);
}