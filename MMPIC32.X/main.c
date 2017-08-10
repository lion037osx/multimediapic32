/*********************************************************************
 ********************************************************************/
#include <plib.h>

//#pragma config FPBDIV = DIV_8

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2	
#pragma config FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL

#include "System.h"

static unsigned int count=0;

int main(void){
inits();    
run();  
}

#ifdef __INTERRUPT_EXTERNAL1__    
void __ISR(_EXTERNAL_1_VECTOR,IPL7AUTO)  ExtInt1_ISR(void){
    LED_RA0=1;
    IFS0bits.INT1IF=0;  
}
#endif

#ifdef __TIMER1__

void __ISR(_TIMER_1_VECTOR,IPL6SOFT) Timer1Handler(void)
{
    if(count>=500){
    updateClock();
    count=0;
    }
count++;
IFS0bits.T1IF = 0;
}
#endif

#ifdef __TIMER2__
void __ISR(_TIMER_2_VECTOR,ipl6AUTO) Timer1Handler(void)
{
    IFS0bits.T2IF = 0;
}
#endif

