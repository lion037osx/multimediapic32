#include "interrupts.h"
//#include "SystemClock.h"
#include <plib.h>


void ConfigInterruptTimer2(void){
T2CON = 0x0;           // Stop the timer and clear the control register,
// prescaler at 1:1,internal clock source
TMR2 = 0x0;            // Clear the timer register 
PR2 = 0xFFFF;          // Load the period register 
IPC2SET = 0x0000000C;  // Set priority level = 3
IPC2SET = 0x00000001;  // Set subpriority level = 1
// Can be done in a single operation by assigning PC2SET = 0x0000000D
IFS0CLR = 0x00000100;  // Clear the timer interrupt status flag 
IEC0SET = 0x00000100;  // Enable timer interrupts
T2CONSET = 0x8000;     // Start the timer
}

void ConfigInterruptExternal1(void){
IEC0bits.INT1IE = 0; // disable INT0 interrupt //Interrupt Enable Control Register 
INTCONbits.INT1EP = 1; // edge polarity ( 1 rising, 0 falling edge ) //Interrupt Control Register
IPC1bits.INT1IP= 7; // interrupt priority//Interrupt Priority Control Register
IPC1bits.INT1IS = 0; // interrupt sub priority//Interrupt Priority Control Register
IFS0bits.INT1IF= 0; // clear INT0 flag//Interrupt Flag Status Register.
IEC0bits.INT1IE = 1; // enable INT0 interrupt//Interrupt Enable Control Register

}

void ConfigInterrupts(void){
//ConfigInterruptTimer2();
ConfigInterruptExternal1();
INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
INTEnableInterrupts();
}