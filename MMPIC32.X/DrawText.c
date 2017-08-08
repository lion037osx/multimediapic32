#include "GOLFont.h"
#include "Primitive.h"
//#include "debug.h"
#include "clock/setttingsRtcc.h"
#include "DrawGraphics.h"
#include "DrawText.h"
#include "Graphics/Ssd1963.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
#include <p32xxxx.h>
//#include <plib.h>


#define STRLEN(BYTES)   3
#define byte __GOLFontDefault

static const BYTE __GOLFontDefault[] __attribute__((aligned(2)));

void debug(BYTE *p , DWORD value){
#ifdef __DEBUG__    
    static char str[64];
    sprintf(str,"%s: 0x%X\r\n",p,value);
    UARTPutString(str);
#endif
//return;
}

WORD func_draw_txt(WORD start_x , WORD start_y , BYTE ascii ,WORD font_color){
static FONT_HEADER font;
static WORD width;
static DWORD address_ascii;
static DWORD array_pix;
static WORD x,y;
static WORD counter_byte;

font.firstChar= byte[3]<<8 | byte[2];
font.height=byte[7]<<8 | byte[6];

#ifdef __DEBUG__ 
debug ("\r\n",0x00);
debug("font.firstChar",font.firstChar);
debug("height",font.height);
#endif

width=byte[0x08+((ascii-28)*4)];

debug("Width",width);

if( (width>=0x00) && (width<=0x07)){counter_byte=1;}
else if( (width>=0x08) && (width<=0x10)){counter_byte=2;}
else if( (width>=0x11) && (width<=0x18) ){counter_byte=3;}
else{counter_byte=0;}

#ifdef __DEBUG__ 
    debug("counter_byte:", counter_byte );
#endif

address_ascii=((byte[0x3+0x08+((ascii-28)*4)])<<16)&0xFF0000|( (byte[0x2+0x08+((ascii-28)*4)])<<8)&0xFF00 | (byte[0x1+0x08+((ascii-28)*4)]&0xFF);
#ifdef __DEBUG__ 
    debug("byte 2" , byte[0x3+0x08+((ascii-28)*4)]);
    debug("byte 1" , byte[0x2+0x08+((ascii-28)*4)]);
    debug("byte 0" , (byte[0x1+0x08+((ascii-28)*4)])&0xFF);
#endif    
   {

    #ifdef __DEBUG__
        debug("address" , address_ascii);
    #endif
    
    for(y=start_y;y<(font.height+start_y);y++)
    {
    switch(counter_byte){
        case 1:
                    array_pix =  (byte[address_ascii])&0xFF;
            break;
        case 2:
                    array_pix = (byte[address_ascii+1] << 8)%0xFF00 | (byte[address_ascii])&0xFF;
            break;
        case 3:
                    array_pix = (byte[address_ascii+2] <<16)&0xFF0000 | (byte[address_ascii+1]<<8)&0xFF00 | (byte[address_ascii])&0xFF;
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
    x=x+func_draw_txt(x,y,*str++,color_font);    
return x;
}

void drawText(void){
static WORD x,y;
static WORD deb;

    x=48;
    y=48;
    //str_draw_txt((480/2)-48,96,"23:30");
    deb=str_draw_txt(4,4," @ProjecT Graphics lion OSX ... ",GRAY6);
    #ifdef __DEBUG__
        debug("value return x:",deb);
    #endif
//return;
}


void draw_clock(MCP79401 rtcc){
static BYTE str[32];
static MCP79401 ram_rtcc;

#ifdef __DEBUG__
    debug("debug year",rtcc.year);
    debug("debug month",rtcc.month);
    debug("debug day",rtcc.date);
    debug("debug hour",rtcc.hour);
    debug("debug min",rtcc.min);
    debug("debug sec",rtcc.sec);
#endif
    
    sprintf(str,"%d.%d%d.%d%d",ram_rtcc.year,(ram_rtcc.month>>4)&0x7,ram_rtcc.month&0xf,(ram_rtcc.date>>4)&0x7,ram_rtcc.date&0xf);
    //sprintf(str,"%d %s %d%d",rtcc.year,str_month(rtcc.month),(rtcc.day>>4)&0x7,rtcc.day&0xf);
    str_draw_txt(200,96,str,COLOR_BACKGROUND);
    sprintf(str,"%d%d:%d%d",(ram_rtcc.hour>>4)&0x7,ram_rtcc.hour&0xf,(ram_rtcc.min>>4)&0x7,ram_rtcc.min&0xf);    
    str_draw_txt(200,64,str,COLOR_BACKGROUND);             

    sprintf(str,"%d.%d%d.%d%d",rtcc.year,(rtcc.month>>4)&0x7,rtcc.month&0xf,(rtcc.date>>4)&0x7,rtcc.date&0xf);
    //sprintf(str,"%d %s %d%d",rtcc.year,str_month(rtcc.month),(rtcc.day>>4)&0x7,rtcc.day&0xf);
    str_draw_txt(200,96,str,COLOR_FONT_CLOCK);
    sprintf(str,"%d%d:%d%d",(rtcc.hour>>4)&0x7,rtcc.hour&0xf,(rtcc.min>>4)&0x7,rtcc.min&0xf);    
    str_draw_txt(200,64,str,COLOR_FONT_CLOCK); 
    ram_rtcc=rtcc;
//return;
}