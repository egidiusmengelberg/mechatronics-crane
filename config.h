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
    #define motor_z_down_time 3000

    #define axis_x_min 1
    #define axis_x_max 10

    #define axis_y_min 1
    #define axis_y_max 6


//INPUTS

    //AXIS BUTTONS
    #define button_home_x_ddr DDRA // pin 23
    #define button_home_x_pin PINA
    #define button_home_x_port PORTA
    #define button_home_x_num PA1

    #define button_home_y_ddr DDRA // pin 25
    #define button_home_y_pin PINA
    #define button_home_y_port PORTA
    #define button_home_y_num PA3

    #define button_min_z_ddr DDRA // pin 27
    #define button_min_z_pin PINA
    #define button_min_z_port PORTA 
    #define button_min_z_num PA5

    #define button_position_x_ddr DDRC // pin 33
    #define button_position_x_pin PINC
    #define button_position_x_port PORTC
    #define button_position_x_num PC4

    #define button_position_y_ddr DDRC // pin 31
    #define button_position_y_pin PINC
    #define button_position_y_port PORTC
    #define button_position_y_num PC6

    //UI BUTTONS
    #define button_ui_up_ddr DDRH // pin 6
    #define button_ui_up_pin PINH
    #define button_ui_up_port PORTH
    #define button_ui_up_num PH3

    #define button_ui_down_ddr DDRE //pin 5
    #define button_ui_down_pin PINE
    #define button_ui_down_port PORTE
    #define button_ui_down_num PE3

    #define button_ui_select_ddr DDRG //pin 4
    #define button_ui_select_pin PING
    #define button_ui_select_port PORTG
    #define button_ui_select_num PG5
    
    #define button_ui_start_ddr DDRE // pin 3
    #define button_ui_start_pin PINE
    #define button_ui_start_port PORTE
    #define button_ui_start_num PE5

//OUTPUTS

    //RELAYS
    #define relay_x_ddr DDRC //30
    #define relay_x_port PORTC
    #define relay_x_num PC7

    #define relay_y_ddr DDRC //32
    #define relay_y_port PORTC
    #define relay_y_num PC5

    #define relay_z_ddr DDRA //28
    #define relay_z_port PORTA
    #define relay_z_num PA6

    #define relay_magnet_ddr DDRA //26
    #define relay_magnet_port PORTA
    #define relay_magnet_num PA4

    //LIGHTS
    #define light_panel_ddr DDRE //2
    #define light_panel_port PORTE
    #define light_panel_num PE4

//INTERFACES

    //DISPLAY
    #define display_din_ddr DDRC //34
    #define display_din_port PORTC
    #define display_din_num PC3

    #define display_clk_ddr DDRD //38
    #define display_clk_port PORTD
    #define display_clk_num PD7

    #define display_cs_ddr DDRC // 36
    #define display_cs_port PORTC
    #define display_cs_num PC1

    //MOTOR
    #define motor_en_l_ddr DDRA // pin 24
    #define motor_en_l_port PORTA
    #define motor_en_l_num PA2

    #define motor_en_r_ddr DDRA // pin 22
    #define motor_en_r_port PORTA
    #define motor_en_r_num PA0

#endif