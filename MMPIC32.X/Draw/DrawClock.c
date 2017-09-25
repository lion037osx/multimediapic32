


#include <GenericTypeDefs.h>
#include "../HardwareProfile.h"
#include "DrawClock.h"
#include "../Graphics/Ssd1963.h"		//include the command table for SSD1963
#include "../TimeDelay.h"			//required for DelayMs(xx) software delay
#include "../Graphics/Tft.h"				//configuration for individual TFT panels
#include "../config/ConfigHardware.h"

extern WORD	_color;
extern WORD _palletBackGroundColor;

WORD setClearClockColor(void){    
    #ifdef __MEMORY_RAM__ 
    return (_palletBackGroundColor);
   #endif
#ifdef __MEMORY_FLASH__ 
   // return (_palletBackGroundColor);
    return (COLOR_BACKGROUND_CLOCK);
#endif
}