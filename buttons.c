#include "buttons.h"

void initButtons() {
    //ui buttons as input
    button_ui_up_ddr &= ~(1 << button_ui_up_num);
    button_ui_down_ddr &= ~(1 << button_ui_down_num);
    button_ui_select_ddr &= ~(1 << button_ui_select_num);
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