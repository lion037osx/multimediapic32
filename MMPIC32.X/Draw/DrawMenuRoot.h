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
    WIFI           
}CONFIG_t;

typedef enum wifi_config{
    IP,
    NETMASK,
    PORT            
}WIFI_CFG;



bool menumMaster(int flag);
void drawInitMenu(void);
#ifdef	__cplusplus
}
#endif

#endif	/* DRAWMENUROOT_H */

