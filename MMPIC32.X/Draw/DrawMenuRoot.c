#include "DrawMenuRoot.h"
#include "DrawIcons.h"
#include "../ConfigHardware.h"
#include "../Graphics/Colors.h"
#include "../Graphics/Ssd1963.h"
#include <stdint.h>
#include <plib.h>
#include <GenericTypeDefs.h>

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
    return (GRAY4);
    //return (COLOR_BACKGROUND);
}

WORD setColorFrontIcon(){
    return (LIGHTGREEN);
}

bool menumMaster(int flag){
    
    static int menu=0;
    static UINT startLeft=(DISP_HOR_RESOLUTION/(STRLEN_MENU+2));
    static int toolBarVert = DISP_VER_RESOLUTION - 48;  
      if(get_portb4()==0 || flag==TRUE){
          
          
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
         menu++;
        if(menu>8){menu=0;}
         flag=FALSE;
        return (TRUE);
    }
      else {
          return (FALSE);
      }
}


void drawInitMenu(void){
    static int rigth;
    rigth=9;
    while( rigth-- )menumMaster(TRUE);
}

void config(int select){

switch(select){

    
}    
    
    
}