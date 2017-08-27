


#include <GenericTypeDefs.h>
#include "../HardwareProfile.h"
#include "DrawClock.h"

extern WORD _palletBackGroundColor;

WORD setClearClockColor(void){    
    #ifdef __MEMORY_RAM__ 
    return (_palletBackGroundColor);
   #endif
#ifdef __MEMORY_FLASH__ 
    return (_palletBackGroundColor);
#endif
}