

#include "../HardwareProfile.h"
#include "../config/ConfigHardware.h"
#include "../Graphics/Colors.h"
#include "../Graphics/Ssd1963.h"

#include "../Graphics/Tft.h"

#include <stdint.h>
#include <plib.h>
#include <GenericTypeDefs.h>
#include "../Uart.h"

//#include "../icons/battery32x32.h"
//#include "../icons/check32.h"
#include "../icons/cogs32.h"
#include "../icons/db32.h"
#include "../icons/globe32.h"
#include "../icons/pinmap32.h"
#include "../icons/sun32.h"
#include "../icons/users32.h"
#include "../icons/wrench32.h"  

#include "../clock/setttingsRtcc.h"

#include "DrawIcons.h"
#include "DrawConfigWifi.h"
#include "DrawGraphics.h"
#include "DrawMenuRoot.h"
#ifdef __MEMORY_RAM__ 
extern WORD _palletBackGroundColor;
#endif

#ifdef __MEMORY_FLASH__
extern WORD _palletBackGroundColor;
extern WORD	_color;
#endif
extern UINT16 flagSetConfig;

WORD setColorClearIcon(){
    #ifdef __MEMORY_RAM__ 
    //return (COLOR_BACKGROUND_ICON);
    return (_palletBackGroundColor);
   #endif
#ifdef __MEMORY_FLASH__ 
    return (_palletBackGroundColor);
//    return (COLOR_BACK_ICON);
#endif
}

WORD setColorIconOff(){
    return (COLOR_ICON_OFF);
}

WORD setColorFrontIcon(){
    return (COLOR_ICON_ON);
}

void iconsInactiveMenu(void){
        static UINT startLeft=(DISP_HOR_RESOLUTION/(STRLEN_MENU+2));
    static int toolBarVert = DISP_VER_RESOLUTION - 48;  

  //      draw_icon( startLeft + (BATTERY*startLeft) ,toolBarVert ,(void *)&battery,setColorIconOff());

//        draw_icon( startLeft + (CHECK*startLeft),toolBarVert ,(void *)&check,setColorIconOff());
  
        draw_icon( startLeft + (SUN*startLeft),toolBarVert ,(void *)&sun32,setColorIconOff());
   
        draw_icon( startLeft + (HOUSE*startLeft),toolBarVert ,(void *)&globe32,setColorIconOff());

        draw_icon( startLeft + (CONFIG*startLeft),toolBarVert ,(void *)&cogs32,setColorIconOff());
  
        draw_icon( startLeft + (DATABASE*startLeft),toolBarVert ,(void *)&db32,setColorIconOff());
    
        draw_icon( startLeft + (PIN_MAP*startLeft) ,toolBarVert ,(void *)&pinmap32,setColorIconOff());
  
        draw_icon( startLeft + (USERS*startLeft) ,toolBarVert ,(void *)&users32,setColorIconOff());

}

bool menumMaster(int flag){
    
    static int menu=0;
    static char str[40];
    static UINT startLeft=(DISP_HOR_RESOLUTION/(STRLEN_MENU+2));
    static int toolBarVert = DISP_VER_RESOLUTION - 48;  
      if(get_portb4()==0 || flag==TRUE){
              
          while(get_portb4()==0);
          LED_RA3=~LED_RA3;

   
        switch (menu-1){
                            /*
            case BATTERY:
                draw_icon( startLeft + (BATTERY*startLeft) ,toolBarVert ,(void *)&battery,setColorIconOff());
                    break;
            case CHECK:   
                draw_icon( startLeft + (CHECK*startLeft),toolBarVert ,(void *)&check,setColorIconOff());
                    break;        */
            case SUN:       
                draw_icon( startLeft + (SUN*startLeft),toolBarVert ,(void *)&sun32,setColorIconOff());
                    break;
            case HOUSE:       
                draw_icon( startLeft + (HOUSE*startLeft),toolBarVert ,(void *)&globe32,setColorIconOff());
                    break;
            case CONFIG: 
                //LED_RA3=~LED_RA3;
//                sprintf(str,"SET CONFIG:%d\r\n",flagSetConfig);

                if(flagSetConfig>=1){
                    UARTPutString(str);
                    flagSetConfig=0;
                    menu--;
                    configAll();
                }
                draw_icon( startLeft + (CONFIG*startLeft),toolBarVert ,(void *)&cogs32,setColorIconOff());
                    break;
            case DATABASE:       
                draw_icon( startLeft + (DATABASE*startLeft),toolBarVert ,(void *)&db32,setColorIconOff());
                    break;
            case PIN_MAP:       
                draw_icon( startLeft + (PIN_MAP*startLeft) ,toolBarVert ,(void *)&pinmap32,setColorIconOff());
                    break;
            case USERS:       
                draw_icon( startLeft + (USERS*startLeft) ,toolBarVert ,(void *)&users32,setColorIconOff());
                    break;
            default:
                    break;
        }   
       
        switch (menu){
                /*
            case BATTERY:
                 clearDesktop();
                draw_icon( startLeft + (BATTERY*startLeft) ,toolBarVert ,(void *)&battery,setColorFrontIcon());
                    break;
            case CHECK:   
                  clearDesktop();
                draw_icon( startLeft + (CHECK*startLeft),toolBarVert ,(void *)&check,setColorFrontIcon());
                    break;    */    
            case SUN:       
                clearDesktop();
                draw_icon( startLeft + (SUN*startLeft),toolBarVert ,(void *)&sun32,setColorFrontIcon());
                    break;
            case HOUSE:        
                clearDesktop();
                draw_icon( startLeft + (HOUSE*startLeft),toolBarVert ,(void *)&globe32,setColorFrontIcon());
                    break;
            case CONFIG: 
                //    clearDesktop();                    
                    drawConfigWifi();      
                draw_icon( startLeft + (CONFIG*startLeft),toolBarVert ,(void *)&cogs32,setColorFrontIcon());
                        
                    break;
            case DATABASE:     
                clearDesktop();
                draw_icon( startLeft + (DATABASE*startLeft),toolBarVert ,(void *)&db32,setColorFrontIcon());
                    break;
            case PIN_MAP:      
                clearDesktop();
                draw_icon( startLeft + (PIN_MAP*startLeft) ,toolBarVert ,(void *)&pinmap32,setColorFrontIcon());
                    break;
            case USERS:       
                clearDesktop();
                draw_icon( startLeft + (USERS*startLeft) ,toolBarVert ,(void *)&users32,setColorFrontIcon());
                    break;
            default://menu=0;
                    break;
        }   
        //flagSetConfig=0;
         menu++;
        if(menu>6){menu=0;}
         flag=FALSE;
        return (TRUE);
    }
      else { 
          //flagSetConfig=0;
          return (FALSE);
      }
}


void drawInitMenu(void){
iconsInactiveMenu();
}

void configTime(void){
static UINT8 select=0;
static MCP79401 clock;
//clock=get_time();

clock.hour=0x00;
clock.min=0x00;
clock.year=0x00;
clock.month=0x01;
clock.date=0x01;

    switch(select){
        case CFG_YEAR:
            clock.year=0x00;
                UARTPutString("function config Year\r\n");
            break;
        case CFG_MONTH:
            clock.month=0x01;
                UARTPutString("function config Month\r\n");
            break;
        case CFG_DATE:
            clock.date=0x01;
                UARTPutString("function config Date\r\n");
            break;
        case CFG_HOUR:
            clock.hour=0x00;
                UARTPutString("function config Hour\r\n");
            break;
        case CFG_MIN:
            clock.min=0x00;
                UARTPutString("function config Min\r\n");
            break;
        case CFG_SECOND:
            //clock.sec=START_32KHZ;
                UARTPutString("function config Second\r\n");
            break;
        default:
            break;
    }          
    //settingsClock(clock);
    
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


void draw_tool_bar(void){

static WORD pixel_y,strlen_x,x,y;
_color=COLOR_TOOL_BAR;
strlen_x=480;
y=272-64;

while(y<272){
    x=0;  
    while(x<strlen_x){          
            PutPixel( x, y );          
            x++;                      
        }
    y++;
    }
}