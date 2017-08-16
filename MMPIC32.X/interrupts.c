#include "interrupts.h"
#include <plib.h>
#include "HardwareProfile.h"


/*
#define FOSC 80000000
#define PB_DIV 8
#define PRESCALE 256
#define TICKS_PER_SEC 4
#define T1_TICK_RATE (FOSC/PB_DIV/PRESCALE/TICKS_PER_SEC)
//OpenTimer1(T1_ON | T1_SOURCE_INT | T1_PS_1_256, T1_TICK_RATE);
//ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_3);
 //* EXAMPLE 2
PRI=62499;//example for (16M/256)-1=PRI //for (80M/256)-1=312499=0x4C4B3h=PRI 
TMR1=0;
T1CONbits.TCKPS=3;
T1CONbits.TCS=0;
T1CONbits.ON=1;
IPC1bits.T1IP=5;
IPC1bits.T1IS=0;
IFS0bits.T1IF=0;
IEC0bits.T1IE=1;
 
INTEnableSystemMultiVectoredInt();
*/


void ConfigInterruptTimer1(void){
#ifdef __TIMER1__    
T1CONbits.ON = 0x0;           // Stop the timer and clear the control register,
// prescaler at 1:1,internal clock source
TMR1 = 0x0;            // Clear the timer register 
PR1 = 0xFFFF;          // Load the period register 
IPC1bits.T1IP = 6;  // Set priority level = 3
IPC1bits.T1IS = 1;  // Set subpriority level = 1
// Can be done in a single operation by assigning PC2SET = 0x0000000D
IFS0bits.CTIF = 0;  // Clear the timer interrupt status flag 
IEC0bits.T1IE = 1;  // Enable timer interrupts
T1CONbits.ON = 1;     // Start the timer
//OpenTimer1(T1_ON | T1_SOURCE_INT | T1_PS_1_256, 0xFFFF);
// set up the core timer interrupt with a prioirty of 2 and zero sub-priority
//ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_2);
#endif
}

void ConfigInterruptTimer2(void){
#ifdef __TIMER2__    
T2CON = 0x0;           // Stop the timer and clear the control register,
// prescaler at 1:1,internal clock source
TMR2 = 0x0;            // Clear the timer register 
PR2 = 0xFFFF;          // Load the period register 
IPC2bits.T2IP=6;  // Set priority level = 3
IPC2bits.T2IS=1;  // Set subpriority level = 1
// Can be done in a single operation by assigning PC2SET = 0x0000000D
IFS0CLR = 0x00000100;  // Clear the timer interrupt status flag 
IEC0SET = 0x00000100;  // Enable timer interrupts
T2CONSET = 0x8000;     // Start the timer
#endif
}

void ConfigInterruptExternal1(void){
#ifdef __INTERRUPT_EXTERNAL1__    
    IEC0bits.INT1IE = 0; // disable INT0 interrupt //Interrupt Enable Control Register 
    INTCONbits.INT1EP = 1; // edge polarity ( 1 rising, 0 falling edge ) //Interrupt Control Register
    IPC1bits.INT1IP= 7; // interrupt priority//Interrupt Priority Control Register
    IPC1bits.INT1IS = 0; // interrupt sub priority//Interrupt Priority Control Register
    IFS0bits.INT1IF= 0; // clear INT0 flag//Interrupt Flag Status Register.
    IEC0bits.INT1IE = 1; // enable INT0 interrupt//Interrupt Enable Control Register
#endif    
}

void ConfigInterrupts(void){
#ifdef __TIMER1__      
    ConfigInterruptTimer1();
#endif      
    
#ifdef __TIMER2__      
    ConfigInterruptTimer2();
#endif    
#ifdef __INTERRUPT_EXTERNAL1__    
    ConfigInterruptExternal1();
#endif
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);

}

