
#include "../Graphics/Ssd1963.h"

#ifdef __LOGO__
    #include "../icons/logo.h"
#else
    #include "../drivers/SST25VF016.h"
#endif
/*
void showLogo(void){      
static int x,y;
DWORD address=0x0000;

#ifdef __LOGO__
    BYTE *bmp ;
    bmp=(void *)&new_bmp;
#endif
    
address=18;

y=0;
while(y<272)
   // for(y=0;y<272;y++)
    {
    x=0;
    while(x<(480))
        //for(x=0;x<480;x++)
        {
        #ifdef __LOGO__
            _color= ((bmp[address+1]<<8)&0xFF00|(bmp[address]&0xFF));
        #else

       _color= ((SST25ReadByte(address+1)<<8)|(SST25ReadByte(address)));
       
     // _color = (WORD *)((SST25ReadByte(address)<<8)&0xFF00 | (SST25ReadByte(address+1))&0xFF);
       
    //     _color= (WORD )((SST25ReadWord(address))&0xFFFF);
        #endif
            PutPixel(x,y);

            address=address+2;
           // address++;
           x++;
        }   
    y++;
    }
}
*/





void showLogo(void){      
static WORD x,y;
static DWORD address;

#ifdef __LOGO__
    BYTE *bmp ;
    bmp=(void *)&new_bmp;
#endif
    
address=18;
y=272;
while(y--)
//    for(y=0;y<272;y++)
    {
    x=0;
    while(x<480)
  //      for(x=0;x<480;x++)
        {
        #ifdef __LOGO__
            _color= ((bmp[address+1]<<8)&0xFF00|(bmp[address]&0xFF));
        #else
        _color= ((SST25ReadByte(address+1)<<8)|(SST25ReadByte(address)));
        //_color= (WORD )((SST25ReadWord(address))&0xFFFF);
        #endif
            PutPixel(x,y);
           address=address+2;
          x++;
        }         
    }
}
