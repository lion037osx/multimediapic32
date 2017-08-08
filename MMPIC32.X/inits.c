#include "SystemClock.h"
#include "Uart.h"
#include "ConfigHardware.h"
#include "Graphics/Ssd1963.h"
#include "Graphics/Colors.h"
#include "interrupts.h"


void inits(void){
DDPCONbits.JTAGEN = 0;	//disable the JTAG port
SYSTEMConfigPerformance(GetSystemClock());
ConfigInterrupts();
ConfigBackligth();
ConfigHardwareLeds();
ConfigClearAllLeds();
UARTInit();
ResetDevice();//graphics function
_color=COLOR_BACKGROUND;
ClearDevice();
BACKLIGTH=1;

initClock();

}