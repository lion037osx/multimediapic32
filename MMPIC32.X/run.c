//#include "Uart.h"
//#include <GenericTypeDefs.h>
#include <plib.h>
#include "Draw/DrawGraphics.h"
#include "clock/setttingsRtcc.h"
#include "ConfigHardware.h"
#include "run.h"
#include "Draw/DrawMenuRoot.h"


void run(void){
UARTPutString("Welcome my app\r\n");
home_draw();

draw_tool_bar();

drawInitMenu();
while(1){
        
           LED_RA0=0;
           if(menumMaster(FALSE));
    }
}

void updateClock(void){
if(func_clock()){LED_RA1=~LED_RA1;}
}