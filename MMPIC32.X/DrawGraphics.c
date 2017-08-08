#include "DrawIcons.h"
//#include "System.h"n

//#include <GenericTypeDefs.h>
//#include "Colors.h"
#include "ConfigHardware.h"
#include "Graphics/Ssd1963.h"
#include "Graphics/Tft.h"

void buttonSelect(UINT8 select){
static UINT16 start_y,end_y;
start_y=HEIGHT_SCREEN-48+1;
end_y=HEIGHT_SCREEN-1;

    switch(select){
        case 0:
                  // drawButtons(BRIGHTBLUE,0,120,start_y,end_y);    
                    break;
        case 1:
                    //drawButtons(GRAY6,0,120,start_y,end_y);
                    break;
        case 2:
                    //drawButtons(BRIGHTBLUE,120,240,start_y,end_y);
                    break;
        case 3:
                    //drawButtons(GRAY6,120,240,start_y,end_y);
                    break;
        case 4:
                    //drawButtons(BRIGHTBLUE,240,360,start_y,end_y);
                    break;
        case 5:
                    //drawButtons(GRAY6,240,360,start_y,end_y);
                    break;
        case 6:
                    //drawButtons(BRIGHTBLUE,360,480,start_y,end_y);
                    break;
        case 7:
                    //drawButtons(GRAY6,360,480,start_y,end_y);
                     break;
        default :
                    return ;
                    break;    
    }
}


void setColor(WORD color){
_color=color;
}

void drawButtons(void){
static CONFIG_BUTTON_t button;    

button.setColorFront=GRAY6;
button.setColorBack=GRAY1;
button.start_x=0;
button.end_x=WIDTH_SCREEN/4;
button.start_y=HEIGHT_SCREEN-64;
button.end_y=HEIGHT_SCREEN;

setColor(button.setColorFront); 
SetArea(button.start_x,button.start_y,button.end_x,button.end_y);
button.start_x=button.end_x;
button.end_x=button.end_x+WIDTH_SCREEN/4;

SetArea(button.start_x,button.start_y,button.end_x,button.end_y);
button.start_x=button.end_x;
button.end_x=button.end_x+WIDTH_SCREEN/4;

SetArea(button.start_x,button.start_y,button.end_x,button.end_y);
button.start_x=button.end_x;
button.end_x=button.end_x+WIDTH_SCREEN/4;

SetArea(button.start_x,button.start_y,button.end_x,button.end_y);
//button.start_x=button.end_x;
//button.end_x=button.end_x+WIDTH_SCREEN/4;

}



void init_buttons_draw(void){
drawButtons();
}

void draw_icon(WORD start_x ,WORD start_y ,BYTE *bmp){    
static WORD search_i,pixel_y,pixel_x,strlen_x,strlen_y;

strlen_x=(bmp[5]<<8)|bmp[4];
pixel_y=strlen_y=(bmp[3]<<8)|bmp[2];
search_i=18;

while(pixel_y--){
    pixel_x=0;  
    while(pixel_x<strlen_x){        
            _color=((bmp[search_i+1]<<8)&0XFF00|(bmp[search_i]&0xFF));   
            if(_color<WHITE){             
                _color=GRAY4;
                PutPixel( (pixel_x+start_x) , (pixel_y+start_y) );          
            }
         search_i=search_i+2;
         pixel_x++;                      
        }
    }
}


void home_draw(void ){
    static UINT start_x;
    start_x=48;

    _color=COLOR_BACKGROUND;
    ClearDevice();
    drawText();

    draw_icon( start_x ,272-64 ,(void *)&battery); start_x=start_x+48;
    draw_icon( start_x ,272-64 ,(void *)&check); start_x=start_x+48;
    draw_icon( start_x ,272-64 ,(void *)&sun32);start_x=start_x+48;
    draw_icon( start_x ,272-64 ,(void *)&globe32);start_x=start_x+48;
    draw_icon( start_x ,272-64 ,(void *)&cogs32);start_x=start_x+48;
    draw_icon( start_x ,272-64 ,(void *)&db32);start_x=start_x+48;
    draw_icon( start_x ,272-64 ,(void *)&wrench32);start_x=start_x+48;
    draw_icon( start_x ,272-64 ,(void *)&users32);start_x=start_x+48;      
//return;
}