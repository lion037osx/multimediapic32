#include "tsc2046.h"
//#include <GenericTypeDefs.h>
#include "spiTsc2046.h"
//#include <stdbool.h>
#include <plib.h>
#include "../ConfigHardware.h"
#include "../TimeDelay.h"

UINT16 getCmdTsc2046(UINT8 cmd)
{
 UINT8 i;
 INT16 tmp16;

    // TODO: make defines for these ports/bits...
    //TRISESET = 0x000C; 
    // Normally these are D2 & D3 LCD outputs; Set as inputs                         // for use with the TSC: D2=BUSY; D3=SDI (serial data from TSC)
    TSC_SCK_LO();        // Init clock line low
    DelayUs(2);    
    TSC_CSn_LO();        // Activate TSC (chip select)
    DelayUs(2);
    // Send the command byte
    for(i = 0x80; i; i>>=1)   // Shift a bit-mask from left to right
    {
        // Set up the data line
        if(i & cmd)  TSC_MOSI_HI();
        else         TSC_MOSI_LO();
        DelayUs(2);        
        // Clock the data
        TSC_SCK_HI();
        DelayUs(2);
        TSC_SCK_LO();
    }
    DelayUs(2);
    // Clock / Read-back 16 bits. Only 12 bits are significant
	tmp16 = 0;
    for(i=0; i<16; i++)
    {
        TSC_SCK_HI();
        DelayUs(2);
        TSC_SCK_LO();
        DelayUs(2);
		tmp16 <<= 1;
        tmp16 |= TOUCH_SCREEN_SDI;   // TODO define for port assignment
    }
    DelayUs(2);
    TSC_CSn_HI();        // De-Activate TSC (chip select)
    //TRISECLR = 0x000C;   // Set the LCDs data lines (D2 & D3) as outputs.
    setOutputsTsc2046();
    // Shift the 12 significant bits (currently in the MS bits) down 4 bits.
    tmp16 >>= 4;
    
return (tmp16 & 0x0fff);
}


bool getCoordTsc2046(UINT16 *x ,UINT16 *y){
INT16 tmpX, tmpY;

    // If no touch  detect, return FALSE.
    if(getCmdTsc2046(TSC_Z1) == 0)  return (0);

    tmpX = getCmdTsc2046(TSC_X);      // Read X position
    tmpY = getCmdTsc2046(TSC_Y);      // Read Y position

    // Check the touch still active now, and again after
    // some delay (to debounce the touch)
    if(getCmdTsc2046(TSC_Z1) == 0) return (0);
    DelayMs(20);
    if(getCmdTsc2046(TSC_Z1) == 0) return (0);
    
    // This seems to be a valid touch. Return TRUE, and the x,y values.
    if(TSC_SWAP)
    {
        *x = tmpY;
        *y = tmpX;
    }
    else
    {
        *x = tmpX;
        *y = tmpY;
    }
    return (1);
}

void setOutputsTsc2046(void){
TSC_CS_HI();
TSC_SCK_LO();
TSC_MOSI_LO();
}