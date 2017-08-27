#include <GenericTypeDefs.h>
//#include "../fonts/GOLFont.h"
//#include "../fonts/arial_size8_c32.h"
#include "../Primitive.h"
//#include "debug.h"
#include "../clock/setttingsRtcc.h"
#include "DrawGraphics.h"
#include "DrawText.h"
#include "../Graphics/Ssd1963.h"
#include "DrawClock.h"
#include <p32xxxx.h>
#include "../HardwareProfile.h"
//#include <plib.h>
extern WORD	_color;




#define STRLEN(BYTES)   3

#define font __GOLFontDefault

extern const BYTE __GOLFontDefault[] __attribute__((aligned(2)));


void debug(BYTE *p , DWORD value){
#ifdef __DEBUG__    
    static char str[64];
    sprintf(str,"%s: 0x%X\r\n",p,value);
    UARTPutString(str);
#endif
//return;
}

WORD func_draw_txt(WORD start_x , WORD start_y , BYTE ascii ,WORD font_color){
static FONT_HEADER fontHeader;
static WORD width;
static DWORD address_ascii;
static DWORD array_pix;
static WORD x,y;
static WORD counter_byte;
static int firstChar;
#ifdef __DEBUG__ 
debug("ascii :",ascii);

    UARTPutChar(0x40);
    UARTPutChar(0x20);
    UARTPutChar(ascii);
    UARTPutChar(0x20);
#endif            

fontHeader.firstChar= font[3]<<8 | font[2];
fontHeader.height=font[7]<<8 | font[6];
firstChar=fontHeader.firstChar;
#ifdef __DEBUG__ 
debug ("\r\n",0x00);
debug("font.firstChar",fontHeader.firstChar);
debug("height",fontHeader.height);
#endif

width=font[0x08+((ascii-firstChar)*4)];

debug("Width",width);

if( (width>=0x00) && (width<=0x08)){counter_byte=1;}
else if( (width>=0x09) && (width<=0x10)){counter_byte=2;}
else if( (width>=0x11) && (width<=0x18) ){counter_byte=3;}
else{counter_byte=0;}

#ifdef __DEBUG__ 
    debug("counter_byte:", counter_byte );
#endif

address_ascii=((font[0x3+0x08+((ascii-firstChar)*4)])<<16)&0xFF0000|( ( font[0x2+0x08+((ascii-firstChar)*4)])<<8)&0xFF00 | ( font[0x1+0x08+((ascii-firstChar)*4)]&0xFF);


#ifdef __DEBUG__ 
    debug("font 2" , font[0x3+0x08+((ascii-firstChar)*4)]);
    debug("font 1" , font[0x2+0x08+((ascii-firstChar)*4)]);
    debug("font 0" , ( font[0x1+0x08+((ascii-firstChar)*4)])&0xFF);
#endif    
   {

    #ifdef __DEBUG__
        debug("address" , address_ascii);
    #endif
    
    for(y=start_y;y<(fontHeader.height+start_y);y++)
    {
    switch(counter_byte){
        case 1:
                    array_pix =  (font[address_ascii])&0xFF;
            break;
        case 2:
                    array_pix = (font[address_ascii+1] << 8)%0xFF00 | (font[address_ascii])&0xFF;
            break;
        case 3:
                    array_pix = (font[address_ascii+2] <<16)&0xFF0000 | (font[address_ascii+1]<<8)&0xFF00 | (font[address_ascii])&0xFF;
            break;
            
        default :
            break;            
        }

        #ifdef __DEBUG__         
            debug("array_pix" , array_pix);
        #endif        

            for(x=0;x<width;x++)
            {
                if(( array_pix >> x ) & 0x000001)  
                { 
                    _color = font_color; PutPixel(start_x+x,y); 
                }        
            }
        address_ascii = address_ascii + counter_byte;
        }
    }    
return width;     
}

WORD str_draw_txt(WORD x,WORD y,char* str,WORD color_font){

    while(*str)
    x=x+func_draw_txt(x,y,(char) *str++,color_font);    
return x;
}

void drawText(void){
static WORD x,y;
static WORD deb;

    x=48;
    y=48;
    //str_draw_txt((480/2)-48,96,"23:30");
   
    deb=str_draw_txt(4,4," @Projects Graphics pic32 QT lion OSX... ",COLOR_FRONT_TEXT);
//    deb=str_draw_txt(4,4,"Domotics House ...",GRAY2);
        //deb=str_draw_txt(4,4,"sStT",GRAY1);
        //deb=str_draw_txt(1,4,"0123456789",GRAY1);
         //deb=str_draw_txt(1,32,"abcdefghijklmnopqrstuvwxyz",GRAY1);
         //deb=str_draw_txt(1,64,"ABCDEFGHIJKLMNOPQRSTUVWXYZ",GRAY1);
// deb=str_draw_txt(1,96,",.;:{}[]+*-_#$%&/()=?¡¿!|",GRAY1);
    #ifdef __DEBUG__
        debug("value return x:",deb);
    #endif
//return;
}


void draw_clock(MCP79401 rtcc){
static BYTE str[32];
static MCP79401 ram_rtcc;
#ifdef __DRAW_CLOCK__  
    #ifdef __DRAW_DATE__
        sprintf(str,"20%d%d.%d%d.%d%d",(ram_rtcc.year)>>4,ram_rtcc.year&0x7,(ram_rtcc.month>>4)&0x7,ram_rtcc.month&0xf,(ram_rtcc.date>>4)&0x7,ram_rtcc.date&0xf);
        //sprintf(str,"%d %s %d%d",rtcc.year,str_month(rtcc.month),(rtcc.day>>4)&0x7,rtcc.day&0xf);
        str_draw_txt(200,96,str,COLOR_BACKGROUND);



        sprintf(str,"20%d%d.%d%d.%d%d",(rtcc.year)>>4,rtcc.year&0x7,(rtcc.month>>4)&0x7,rtcc.month&0xf,(rtcc.date>>4)&0x7,rtcc.date&0xf);
        //sprintf(str,"%d %s %d%d",rtcc.year,str_month(rtcc.month),(rtcc.day>>4)&0x7,rtcc.day&0xf);
        str_draw_txt(200,96,str,COLOR_FONT_CLOCK);
    #endif
    sprintf(str,"%d%d:%d%d",(ram_rtcc.hour>>4)&0x7,ram_rtcc.hour&0xf,(ram_rtcc.min>>4)&0x7,ram_rtcc.min&0xf);    
    str_draw_txt(412,230,str,setClearClockColor());     
    
    sprintf(str,"%d%d:%d%d",(rtcc.hour>>4)&0x7,rtcc.hour&0xf,(rtcc.min>>4)&0x7,rtcc.min&0xf);    
    str_draw_txt(412,230,str,COLOR_FONT_CLOCK); 
    ram_rtcc=rtcc;
#endif
}