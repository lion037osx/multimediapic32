//#include "Uart.h"
//#include <GenericTypeDefs.h>
#include <plib.h>
#include "DrawGraphics.h"
#include "clock/setttingsRtcc.h"
#include "ConfigHardware.h"

void run(void){
UARTPutString("Welcome my app\r\n");
home_draw();
while(1){
        if(func_clock());
           LED_RA0=0;
    }
}
