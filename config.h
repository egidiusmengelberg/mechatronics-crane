#ifndef CONFIG_H
#define CONFIG_H

//GENERAL CONFIG
    enum state {
        INIT,
        HOMING,
        MENU,
        MOVING
    };

    enum motor {
        X,
        Y,
        Z
    };

    enum motorDirection {
        FORWARD,
        BACKWARDS
    };

    #define ui_input_delay 200

    #define axis_x_min 1
    #define axis_x_max 12

    #define axis_y_min 1
    #define axis_y_max 12

    #define x_pickup_position 2
    #define y_pickup_position 2


//INPUTS

    //AXIS BUTTONS
    #define button_home_x_ddr DDRF
    #define button_home_x_pin PINF
    #define button_home_x_port PORTF
    #define button_home_x_num PF0

    #define button_home_y_ddr DDRF
    #define button_home_y_pin PINF
    #define button_home_y_port PORTF
    #define button_home_y_num PF1

    #define button_min_z_ddr DDRF
    #define button_min_z_pin PINF
    #define button_min_z_port PORTF 
    #define button_min_z_num PF2

    #define button_max_z_ddr DDRF
    #define button_max_z_pin PINF
    #define button_max_z_port PORTF
    #define button_max_z_num PF3

    #define button_position_x_ddr DDRF
    #define button_position_x_pin PINF
    #define button_position_x_port PORTF
    #define button_position_x_num PF4

    #define button_position_y_ddr DDRF
    #define button_position_y_pin PINF
    #define button_position_y_port PORTF
    #define button_position_y_num PF5

    //UI BUTTONS
    #define button_ui_up_ddr DDRF
    #define button_ui_up_pin PINF
    #define button_ui_up_port PORTF
    #define button_ui_up_num PF1

    #define button_ui_down_ddr DDRF
    #define button_ui_down_pin PINF
    #define button_ui_down_port PORTF
    #define button_ui_down_num PF2

    #define button_ui_select_ddr DDRF
    #define button_ui_select_pin PINF
    #define button_ui_select_port PORTF
    #define button_ui_select_num PF3
    
    #define button_ui_start_ddr DDRF
    #define button_ui_start_pin PINF
    #define button_ui_start_port PORTF
    #define button_ui_start_num PF4

//OUTPUTS

    //RELAYS
    #define relay_x_ddr DDRC
    #define relay_x_port PORTC
    #define relay_x_num PC3

    #define relay_y_ddr DDRC
    #define relay_y_port PORTC
    #define relay_y_num PC4

    #define relay_z_ddr DDRC
    #define relay_z_port PORTC
    #define relay_z_num PC5

    #define relay_magnet_ddr DDRC
    #define relay_magnet_port PORTC
    #define relay_magnet_num PC6

//INTERFACES

    //DISPLAY
    #define display_din_ddr DDRC
    #define display_din_port PORTC
    #define display_din_num PC0

    #define display_clk_ddr DDRC
    #define display_clk_port PORTC
    #define display_clk_num PC1

    #define display_cs_ddr DDRC
    #define display_cs_port PORTC
    #define display_cs_num PC2

    //MOTOR
    #define motor_en_l_ddr DDRC
    #define motor_en_l_port PORTC
    #define motor_en_l_num PC1

    #define motor_en_r_ddr DDRC
    #define motor_en_r_port PORTC
    #define motor_en_r_num PC2

#endif