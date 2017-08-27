//#include "Uart.h"
//#include <GenericTypeDefs.h>
#include <plib.h>
#include "Draw/DrawGraphics.h"
#include "clock/setttingsRtcc.h"
//#include "ConfigHardware.h"
#include "config/ConfigHardware.h"
#include "run.h"
#include "Draw/DrawMenuRoot.h"



void run(void){
UARTPutString("Welcome my app\r\n");

//home_draw();

//draw_tool_bar();

drawInitMenu();
//updateClock();
initClock();
while(1){
        
//           LED_RA0=0;
           if(menumMaster(FALSE));
    }
}

void updateClock(void){
if(func_clock()){LED_RA0=~LED_RA0;}
}