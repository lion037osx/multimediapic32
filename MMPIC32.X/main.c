/*********************************************************************
 ********************************************************************/
#include <plib.h>
//#pragma config FPBDIV = DIV_8

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2	
#pragma config FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL


#include "System.h"
int main(void){
inits();    
run();  
}

void __ISR(_EXTERNAL_1_VECTOR,IPL7SRS)  ExtInt1_ISR(void){
    LED_RA0=1;
IFS0bits.INT1IF=0;  
}