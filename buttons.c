#include "buttons.h"

void initButtons() {
    //ui buttons as input
    button_ui_up_ddr &= ~(1 << button_ui_up_num);
    button_ui_down_ddr &= ~(1 << button_ui_down_num);
    button_ui_select_ddr &= ~(1 << button_ui_select_num);
    button_ui_start_ddr &= ~(1 << button_ui_start_num);

    //ui buttons input pullup
    button_ui_up_port |= (1 << button_ui_up_num);
    button_ui_down_port |= (1 << button_ui_down_num);
    button_ui_select_port |= (1 << button_ui_select_num);
    button_ui_start_port |= (1 << button_ui_start_num);

    //axis buttons as input
    button_home_x_ddr &= ~(1 << button_home_x_num);
    button_home_y_ddr &= ~(1 << button_home_y_num);
    button_min_z_ddr &= ~(1 << button_min_z_num);
    button_max_z_ddr &= ~(1 << button_max_z_num);
    button_position_x_ddr &= ~(1 << button_position_x_num);
    button_position_y_ddr &= ~(1 << button_position_y_num);

    //axis buttons input pullup
    button_home_x_ddr |= (1 << button_home_x_num);
    button_home_y_ddr |= (1 << button_home_y_num);
    button_min_z_ddr |= (1 << button_min_z_num);
    button_max_z_ddr |= (1 << button_max_z_num);
    button_position_x_ddr |= (1 << button_position_x_num);
    button_position_y_ddr |= (1 << button_position_y_num);
}

bool upPressed() {
    return !(button_ui_up_pin & (1 << button_ui_up_num));
}

bool downPressed() {
    return !(button_ui_down_pin & (1 << button_ui_down_num));
}

bool selectPressed() {
    return !(button_ui_select_pin & (1 << button_ui_select_num));
}

bool startPressed() {
    return !(button_ui_start_pin & (1 << button_ui_start_num));
}

bool homeXPressed() {
    return !(button_home_x_pin & (1 << button_home_x_num));
}

bool homeYPressed() {
    return !(button_home_y_pin & (1 << button_home_y_num));
}

bool minZPressed() {
    return !(button_min_z_pin & (1 << button_min_z_num));
}

bool maxZPressed() {
    return !(button_max_z_pin & (1 << button_max_z_num));
}

bool posXPressed() {
    return !(button_position_x_pin & (1 << button_position_x_num));
}

bool posYPressed() {
    return !(button_position_y_pin & (1 << button_position_y_num));
}