/*******************************************************************************
 * File:   typedef_settings.h
 * Author: leo
 *
 * Created on July 26, 2017, 11:36 PM
 ******************************************************************************/

#ifndef TYPEDEF_SETTINGS_H
#define	TYPEDEF_SETTINGS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define IN 1
#define OUT 0    
  /*  
enum menu_master{
    config_all,//seting time //setting temp//SCREEN=>brigth//network,=>ip=>port=>servers_time//server_tmp=>name=>
    screen_domotics,    
};

*/

typedef struct menu_master_t{
UINT8 config_all:8;
UINT8 domotics:8;
}MENU_MASTER;

enum month{
ZERO,
JANUARY=1,
FEBRUARY,
MARCH,
APRIL,
MAY,
JUNE,
JUL,
AUGUST,
SETEMBER,
OCTOBER,
NOVEMBER,
DECEMBER
}MONTH;

enum theme{
        THEME0,
        THEME1,
        THEME2
    }THEME;


enum fonts{
        ARIAL,
        CENTURY_GOTHIC,
        TYME_NEW      
    }FONT_T;

enum settings_men{
        SET_TIME,
        SET_TEMP, //server_time
        SET_SCREEN,        //SCREEN=>brigth//network,=>ip=>port=>servers_time//server_tmp=>name=>
        SET_NETWORK
    }SETTINGS_MENU;

typedef struct  settings_menu_t{
    UINT8 time:4;
    UINT8 temp:4;//server_time
    UINT8 screen:4;        //SCREEN=>brigth//network,=>ip=>port=>servers_time//server_tmp=>name=>
    UINT8 network[4];
}SETTINGS_MENU_T;

enum setting_screen{
    SET_THEME,
    SET_BRIGTH,
    SET_SLEEP
}SET_ON_SCREEN;

typedef struct  setting_screen_t{
UINT8 theme:5;
UINT8 brigth;
UINT8 sleep:1;
}SETTINGS_SCREEN_t;

enum settings_time{
    set_year,
    set_month,
    set_day,
    set_hour,
    set_min,
    set_sec
};

typedef struct  settings_time_t{
    UINT8 year:7;
    UINT8 month:7;
    UINT8 day:7;
    UINT8 hour:7;
    UINT8 min:7;
    UINT8 sec:7;
}SETTINGS_TIME_t;

typedef struct  settings_network_t{
    UINT8 address[4];
    UINT8 netmask[4];//255.255.255.0
    UINT8  gatewoy[4];
    UINT16 port:16;
    UINT32 server_time;
    UINT32 server_temp;
}SETTINGS_NETWORK_t;

enum settings_wifi{
    set_wifi_user,
    set_wifi_password,
    set_wifi_adrress,
    set_wifi_netmask,//255.255.255.0
    set_wifi_gatewoy
};

typedef struct set_wifi_t{
    UINT8 wifi_user[32];
    UINT8 wifi_password[32];
    UINT8 wifi_adrress[4];
    UINT8 wifi_netmask[4];//255.255.255.0
    UINT8 wifi_gatewoy[4];
}SET_WIFI_t;

 typedef struct settings_butt_t{
    WORD color:16;
    UINT16 x_start:10;
    UINT16 x_end:10;
    UINT16 y_start:10;
    UINT16 y_end:10;
}SETTINGS_BUFF_t;

 typedef struct info_bmp_t{
     UINT8 name[32];
    UINT16 width:10;
    UINT16 height:10;
}INFO_BMP;


typedef struct info_icon_t{
     UINT8 name[32];
    UINT16 width:10;
    UINT16 height:10;
}INFO_ICON;

typedef struct  byte_t{
UINT8 bit0:1;
UINT8 bit1:1;
UINT8 bit2:1;
UINT8 bit3:1;
UINT8 bit4:1;
UINT8 bit5:1;
UINT8 bit6:1;
UINT8 bit7:1;
}BYTE_t;


typedef struct size_button_t{
UINT16 start_x:11;
UINT16 start_y:11;
UINT16 end_x:11;
UINT16 end_y:11;
WORD setColorFront;
WORD setColorBack;
}CONFIG_BUTTON_t;

#ifdef	__cplusplus
}
#endif

#endif	/* TYPEDEF_SETTINGS_H */

