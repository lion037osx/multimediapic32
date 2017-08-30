
#include <GenericTypeDefs.h>
#include "../Graphics/Colors.h"
#include "../clock/setttingsRtcc.h"
#include "../Graphics/Ssd1963.h"
#include "DrawText.h"
#include "DrawConfigWifi.h"
#include "DrawGraphics.h"






void drawConfigWifi(void){
   
//str_draw_txt( 10 , 32 , COLOR_FRONT_TEXT );

static char config[]={"ip 192.168.1.39"};
static BYTE *p;
 WORD x_cfg;
 
 clearDesktop();
x_cfg=16 ;
p=(void *)&config;
   while(*p)x_cfg+=func_draw_txt(x_cfg,32,(char) *p++,COLOR_FRONT_TEXT);   
}




