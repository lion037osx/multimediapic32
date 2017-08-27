/***********************************************************************
 *code:  Draw logo 
 *update : 26 08 2017
 * 
 * 
 ************************************************************************/
#include "../Graphics/Ssd1963.h"
#include "../HardwareProfile.h"

#ifdef __MEMORY_FLASH__
#include "../drivers/SST25VF016.h"
extern WORD _palletBackGroundColor;
#else //__MEMORY_RAM__
    #include "../icons/logo.h"
extern WORD _palletBackGroundColor;
#endif

#ifdef __MEMORY_FLASH__
//NEW VERSION
void showLogo(void){      
static SHORT x,y;
DWORD address=0x0000;

#ifdef __LOGO__
    BYTE *bmp ;
    bmp=(void *)&logo;
#endif
    
address=0x6;

while(y<272)
    {
    x=0x0000;
    while(x<480)
        {

        #ifdef __MEMORY_FLASH__

       //_color= ((SST25ReadByte(address+1)<<8)|(SST25ReadByte(address)));
         
      _color= SST25ReadWord(address);
        #endif
            PutPixel(x,y);
            address=address+0x2;
           // address++;
           x++;
        }   
    y++;
    }
_palletBackGroundColor=_color;//(WORD)((bmp[address-2]<<8)&0xFF00 | (bmp[address-1]&0xFF));
}
#endif

#ifdef __MEMORY_RAM__ 

void showLogo(void){      
static SHORT x,y;
DWORD address=0x0000;

static BYTE *bmp ;
bmp=(void *)&logo;

address=0x6;

y=272;
while(y--)
    {
    x=0x0000;
    while(x<480)
        {
        #ifdef __MEMORY_RAM__
            _color= (WORD)((bmp[address+1]<<8)&0xFF00 | (bmp[address]&0xFF));
        #endif
            PutPixel(x,y);
            address=address+0x2;
           x++;
        }   
    }

//_colorBackGround=(WORD)((bmp[address-2]<<8)&0xFF00 | (bmp[address-1]&0xFF));
_palletBackGroundColor=_color;
}
#endif

