//GENERAL CONFIG
    #define ui_input_delay 200

    #define axis_x_min 1
    #define axis_x_max 12

    #define axis_y_min 1
    #define axis_y_max 12

//INPUTS

    //AXIS BUTTONS
    #define button_home_x_ddr
    #define button_home_x_pin
    #define button_home_x_num

    #define button_home_y_ddr
    #define button_home_y_pin
    #define button_home_y_num

    #define button_min_z_ddr
    #define button_min_z_pin
    #define button_min_z_num

    #define button_max_z_ddr
    #define button_max_z_pin
    #define button_max_z_num

    #define button_position_x_ddr
    #define button_position_x_pin
    #define button_position_x_num

    #define button_position_y_ddr
    #define button_position_y_pin
    #define button_position_y_num

    //UI BUTTONS
    #define button_ui_up_ddr DDRF
    #define button_ui_up_pin PINF
    #define button_ui_up_num PF1

    #define button_ui_down_ddr DDRF
    #define button_ui_down_pin PINF
    #define button_ui_down_num PF2

    #define button_ui_select_ddr DDRF
    #define button_ui_select_pin PINF
    #define button_ui_select_num PF3

//OUTPUTS

    //RELAYS
    #define relay_x_ddr DDRC
    #define relay_x_port PORTC
    #define relay_x_num PC0

    #define relay_y_ddr DDRC
    #define relay_y_port PORTC
    #define relay_y_num PC1

    #define relay_z_ddr DDRC
    #define relay_z_port PORTC
    #define relay_z_num PC2

    #define relay_magnet_ddr DDRC
    #define relay_magnet_port PORTC
    #define relay_magnet_num PC3

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
