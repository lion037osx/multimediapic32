#include "DrawMenuRoot.h"
#include "DrawIcons.h"
#include "../ConfigHardware.h"
#include <plib.h>
#include "../Graphics/Colors.h"
//#include "../Graphics/Tft.h"
#include <GenericTypeDefs.h>
#include "../Graphics/Ssd1963.h"

#include <stdint.h>


#include "../icons/battery32x32.h"
#include "../icons/check32.h"
#include "../icons/cogs32.h"
#include "../icons/db32.h"
#include "../icons/globe32.h"
#include "../icons/pinmap32.h"
#include "../icons/sun32.h"
#include "../icons/users32.h"
#include "../icons/wrench32.h"  


WORD setColorClearIcon(){
//_color=COLOR_BACKGROUND;
return (COLOR_BACKGROUND);
}

WORD setColorFrontIcon(){

//return (COLOR_FRONT_ICON);
    return (BRIGHTRED);
}

bool menumMaster(int flag){
    
    static int menu=0;
    static UINT start_left=(DISP_HOR_RESOLUTION/(STRLEN_MENU+2));
    static int toolBarVert = DISP_VER_RESOLUTION - 64;
    //WORD color;
    
      if(get_portb4()==0 || flag==TRUE){
          
          
          while(get_portb4()==0);
          LED_RA3=~LED_RA3;
        switch (menu-1){

            case BATTERY:
                draw_icon( start_left + (BATTERY*start_left) ,toolBarVert ,(void *)&battery,setColorClearIcon());
                    break;
            case CHECK:   
                draw_icon( start_left + (CHECK*start_left),toolBarVert ,(void *)&check,setColorClearIcon());
                    break;        
            case SUN:       
                draw_icon( start_left + (SUN*start_left),toolBarVert ,(void *)&sun32,setColorClearIcon());
                    break;
            case HOUSE:       
                draw_icon( start_left + (HOUSE*start_left),toolBarVert ,(void *)&globe32,setColorClearIcon());
                    break;
            case CONFIG:       
                draw_icon( start_left + (CONFIG*start_left),toolBarVert ,(void *)&cogs32,setColorClearIcon());
                    break;
            case DATABASE:       
                draw_icon( start_left + (DATABASE*start_left),toolBarVert ,(void *)&db32,setColorClearIcon());
                    break;
            case TOOLS:       
                draw_icon( start_left + (TOOLS*start_left) ,toolBarVert ,(void *)&wrench32,setColorClearIcon());
                    break;
            case USERS:       
                draw_icon( start_left + (USERS*start_left) ,toolBarVert ,(void *)&users32,setColorClearIcon());
                    break;
            default:
                    break;
        }               
       
        switch (menu){

            case BATTERY:
                draw_icon( start_left + (BATTERY*start_left) ,toolBarVert ,(void *)&battery,setColorFrontIcon());
                    break;
            case CHECK:   
                draw_icon( start_left + (CHECK*start_left),toolBarVert ,(void *)&check,setColorFrontIcon());
                    break;        
            case SUN:       
                draw_icon( start_left + (SUN*start_left),toolBarVert ,(void *)&sun32,setColorFrontIcon());
                    break;
            case HOUSE:                                       
                draw_icon( start_left + (HOUSE*start_left),toolBarVert ,(void *)&globe32,setColorFrontIcon());
                    break;
            case CONFIG:       
                draw_icon( start_left + (CONFIG*start_left),toolBarVert ,(void *)&cogs32,setColorFrontIcon());
                    break;
            case DATABASE:       
                draw_icon( start_left + (DATABASE*start_left),toolBarVert ,(void *)&db32,setColorFrontIcon());
                    break;
            case TOOLS:       
                draw_icon( start_left + (TOOLS*start_left) ,toolBarVert ,(void *)&wrench32,setColorFrontIcon());
                    break;
            case USERS:       
                draw_icon( start_left + (USERS*start_left) ,toolBarVert ,(void *)&users32,setColorFrontIcon());
                    break;
            default://menu=0;
                    break;
        }        
         menu++;
        if(menu>8){menu=0;}
         flag=FALSE;
        return (TRUE);
    }
      else {
          return (FALSE);
      }
}