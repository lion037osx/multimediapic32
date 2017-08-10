#include <GenericTypeDefs.h>
#include "../Graphics/Ssd1963.h"
#include "../Graphics/Colors.h"

/*
#include "../icons/battery32x32.h"
#include "../icons/check32.h"
#include "../icons/cogs32.h"
#include "../icons/db32.h"
#include "../icons/globe32.h"
#include "../icons/pinmap32.h"
#include "../icons/sun32.h"
#include "../icons/users32.h"
#include "../icons/wrench32.h"   

*/

void draw_icon(WORD start_x ,WORD start_y ,BYTE *bmp ,WORD color)
{    
static WORD search_i,pixel_y,pixel_x,strlen_x,strlen_y;

strlen_x=(bmp[5]<<8)|bmp[4];
pixel_y=strlen_y=(bmp[3]<<8)|bmp[2];
search_i=18;

while(pixel_y--){
    pixel_x=0;  
    while(pixel_x<strlen_x){        
            _color=((bmp[search_i+1]<<8)&0XFF00|(bmp[search_i]&0xFF));   
            if(_color<WHITE)
            {             
                _color=color;
                PutPixel( (pixel_x+start_x) , (pixel_y+start_y) );          
            }
         search_i=search_i+2;
         pixel_x++;                      
        }
    }
}
