#include "../icons/logo.h"
//#include "../icons/domotics13_24bitsC32.h"
#include "../Graphics/Ssd1963.h"

void showLogo(void){
    BYTE *bmp ;
    
static int x,y,i;
   
    bmp=(void *)&new_bmp;
    
i=18;
y=272;
while(y--)
   // for(y=0;y<272;y++)
    {
    x=0;
    while(x<480)
        //for(x=0;x<480;x++)
        {
            _color= ((bmp[i+1]<<8)&0xFF00|(bmp[i]&0xFF));
            PutPixel(x,y);
           i=i+2;
           x++;
        } 
        
    }
}