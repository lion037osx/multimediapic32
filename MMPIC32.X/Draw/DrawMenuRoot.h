/* 
 * File:   DrawMenuRoot.h
 * Author: optimus
 *
 * Created on 9 de agosto de 2017, 21:21
 */

#ifndef DRAWMENUROOT_H
#define	DRAWMENUROOT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <GenericTypeDefs.h>
    
typedef enum menu_enum{
BATTERY,
CHECK,        
SUN,
HOUSE,
CONFIG,
DATABASE,
TOOLS,
USERS,
STRLEN_MENU        
}MenuOrigin_t;

typedef enum config{
    TIME,
    WIFI,
CFG_N_MAX            
}CONFIG_t;

typedef enum wifi_config{
    WIFI_USER,
    WIFI_PASSWORD,
    WIFI_ADDRESS_IP,
    WIF_IP,
    WIFI_NETMASK,
    WIFI_PORT,
WIFI_CFG_N_MAX            
}WIFI_CFG;


typedef struct settings_wifi_t{
    UINT8 wifi_user[32];
    UINT8 wifi_password[32];
    UINT8 wifi_adrress[4];
    UINT8 wifi_netmask[4];//255.255.255.0
    UINT8 wifi_gatewoy[4];
}SETTINGS_WIFI_t;

typedef enum timeClockEnum{
    CFG_YEAR,
    CFG_MONTH,
    CFG_DATE,
    CFG_HOUR,
    CFG_MIN,
    CFG_SECOND,
    CFG_TIME_N_MAX
}RTCC_ENUM;


bool menumMaster(int flag);
void drawInitMenu(void);
void configTime(void);
void configWifi(void);
void configAll(void);
void draw_tool_bar(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DRAWMENUROOT_H */
 
