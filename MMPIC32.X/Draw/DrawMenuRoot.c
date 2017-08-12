#include "DrawMenuRoot.h"
#include "DrawIcons.h"
#include "../ConfigHardware.h"
#include "../Graphics/Colors.h"
#include "../Graphics/Ssd1963.h"
#include <stdint.h>
#include <plib.h>
#include <GenericTypeDefs.h>
#include "../Uart.h"

#include "../icons/battery32x32.h"
#include "../icons/check32.h"
#include "../icons/cogs32.h"
#include "../icons/db32.h"
#include "../icons/globe32.h"
#include "../icons/pinmap32.h"
#include "../icons/sun32.h"
#include "../icons/users32.h"
#include "../icons/wrench32.h"  

#include "../clock/setttingsRtcc.h"

extern UINT16 flagSetConfig;

WORD setColorClearIcon(){
    return (GRAY4);
    //return (COLOR_BACKGROUND);
}

WORD setColorFrontIcon(){
    return (LIGHTGREEN);
}

bool menumMaster(int flag){
    
    static int menu=0;
    static char str[40];
    static UINT startLeft=(DISP_HOR_RESOLUTION/(STRLEN_MENU+2));
    static int toolBarVert = DISP_VER_RESOLUTION - 48;  
      if(get_portb4()==0 || flag==TRUE){
          
          UARTPutString("menuMaster\r\n");
          
          while(get_portb4()==0);
          LED_RA3=~LED_RA3;
        switch (menu-1){

            case BATTERY:
                draw_icon( startLeft + (BATTERY*startLeft) ,toolBarVert ,(void *)&battery,setColorClearIcon());
                    break;
            case CHECK:   
                draw_icon( startLeft + (CHECK*startLeft),toolBarVert ,(void *)&check,setColorClearIcon());
                    break;        
            case SUN:       
                draw_icon( startLeft + (SUN*startLeft),toolBarVert ,(void *)&sun32,setColorClearIcon());
                    break;
            case HOUSE:       
                draw_icon( startLeft + (HOUSE*startLeft),toolBarVert ,(void *)&globe32,setColorClearIcon());
                    break;
            case CONFIG: 
                LED_RA2=~LED_RA2;
                sprintf(str,"SET CONFIG:%d\r\n",flagSetConfig);

                if(flagSetConfig>=1){UARTPutString(str);flagSetConfig=0;menu--;configAll();}
                draw_icon( startLeft + (CONFIG*startLeft),toolBarVert ,(void *)&cogs32,setColorClearIcon());
                    break;
            case DATABASE:       
                draw_icon( startLeft + (DATABASE*startLeft),toolBarVert ,(void *)&db32,setColorClearIcon());
                    break;
            case TOOLS:       
                draw_icon( startLeft + (TOOLS*startLeft) ,toolBarVert ,(void *)&wrench32,setColorClearIcon());
                    break;
            case USERS:       
                draw_icon( startLeft + (USERS*startLeft) ,toolBarVert ,(void *)&users32,setColorClearIcon());
                    break;
            default:
                    break;
        }               
       
        switch (menu){

            case BATTERY:
                draw_icon( startLeft + (BATTERY*startLeft) ,toolBarVert ,(void *)&battery,setColorFrontIcon());
                    break;
            case CHECK:   
                draw_icon( startLeft + (CHECK*startLeft),toolBarVert ,(void *)&check,setColorFrontIcon());
                    break;        
            case SUN:       
                draw_icon( startLeft + (SUN*startLeft),toolBarVert ,(void *)&sun32,setColorFrontIcon());
                    break;
            case HOUSE:                                       
                draw_icon( startLeft + (HOUSE*startLeft),toolBarVert ,(void *)&globe32,setColorFrontIcon());
                    break;
            case CONFIG:       
                draw_icon( startLeft + (CONFIG*startLeft),toolBarVert ,(void *)&cogs32,setColorFrontIcon());
                    break;
            case DATABASE:       
                draw_icon( startLeft + (DATABASE*startLeft),toolBarVert ,(void *)&db32,setColorFrontIcon());
                    break;
            case TOOLS:       
                draw_icon( startLeft + (TOOLS*startLeft) ,toolBarVert ,(void *)&wrench32,setColorFrontIcon());
                    break;
            case USERS:       
                draw_icon( startLeft + (USERS*startLeft) ,toolBarVert ,(void *)&users32,setColorFrontIcon());
                    break;
            default://menu=0;
                    break;
        }   
        //flagSetConfig=0;
         menu++;
        if(menu>8){menu=0;}
         flag=FALSE;
        return (TRUE);
    }
      else { 
          //flagSetConfig=0;
          return (FALSE);
      }
}


void drawInitMenu(void){
    static int rigth;
    rigth=9;
    while( rigth-- )menumMaster(TRUE);
}

void configTime(void){
static UINT8 select=0;
static MCP79401 clock;


//clock=get_time();

clock.hour=0x22;
clock.min=0x28;


clock.year=0x17;
clock.month=0x08;
clock.date=0x10;

    switch(select){
        case CFG_YEAR:
            clock.year=0x17;
                UARTPutString("function config Year\r\n");
            break;
        case CFG_MONTH:
            clock.month=0x08;
                UARTPutString("function config Month\r\n");
            break;
        case CFG_DATE:
            clock.date=0x10;
                UARTPutString("function config Date\r\n");
            break;
        case CFG_HOUR:
            clock.hour=0x22;
                UARTPutString("function config Hour\r\n");
            break;
        case CFG_MIN:
            clock.min=0x30;
                UARTPutString("function config Min\r\n");
            break;
        case CFG_SECOND:
            //clock.sec=START_32KHZ;
                UARTPutString("function config Second\r\n");
            break;
        default:
            break;
    }          
    settingsClock(clock);
    select++;
    if(select>=CFG_TIME_N_MAX){
        select=0;
    }
}


void configWifi(void){
static UINT8 select=0;
static char str[40];
static char str_tmp[40];
    switch(select)
    {    
        case WIFI_USER:
                strcpy(str_tmp,"lionOsx");
                sprintf(str,"USER:%s\r\n",str_tmp);
                UARTPutString(str);
                break;
        case WIFI_PASSWORD:
                strcpy(str_tmp,"*****");
                sprintf(str,"PASSWORD:%s\r\n",str_tmp);
                UARTPutString(str);
                break;
        case WIFI_ADDRESS_IP:
                strcpy(str_tmp,"lionOsx");
                sprintf(str,"ADDRESS IP:%s\r\n",str_tmp);
                UARTPutString(str);            
                break;
        case WIFI_NETMASK:
                strcpy(str_tmp,"255.255.255.0");
                sprintf(str,"NETMASK:%s\r\n",str_tmp);
                UARTPutString(str);            
                break;
        case WIFI_PORT: 
                strcpy(str_tmp,"8080");
                sprintf(str,"PORT:%s\r\n",str_tmp);
                UARTPutString(str);            
                break;
        default:
                break;
    }    
    select++;
    if(select>=WIFI_CFG_N_MAX){
    select=0;
    }
}




void configAll(void){
static UINT8 select=0;

    switch(select){
    case TIME: 
                configTime();
                UARTPutString("function TIME\r\n");
        break;
    case WIFI: 
                UARTPutString("function WIFI\r\n");
                configWifi();
        break;
    default:
        break;
        }          
    select++;
    if(select>=CFG_N_MAX){
        select=0;
    }
}