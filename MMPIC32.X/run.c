//#include "Uart.h"
//#include <GenericTypeDefs.h>
#include <plib.h>
#include "Draw/DrawGraphics.h"
#include "clock/setttingsRtcc.h"
//#include "ConfigHardware.h"
#include "config/ConfigHardware.h"
#include "run.h"
#include "Draw/DrawMenuRoot.h"
#include "Graphics/Ssd1963.h"

void tearing(void){
BACKLIGTH=~BACKLIGTH;
}

void run(void){
UARTPutString("Welcome my app\r\n");
//draw_tool_bar();
drawInitMenu();
initClock();

SetBacklight(127);

while(1){
    //tearing();
        if(menumMaster(FALSE));
    }
}

void updateClock(void){
if(func_clock()){LED_RA0=~LED_RA0;}
}