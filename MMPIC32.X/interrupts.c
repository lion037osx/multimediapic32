#include "interrupts.h"
//#include "SystemClock.h"
#include <plib.h>



void ConfigInterrupts(void){
IEC0bits.INT1IE = 0; // disable INT0 interrupt //Interrupt Enable Control Register 
INTCONbits.INT1EP = 1; // edge polarity ( 1 rising, 0 falling edge ) //Interrupt Control Register
IPC1bits.INT1IP= 7; // interrupt priority//Interrupt Priority Control Register
IPC1bits.INT1IS = 0; // interrupt sub priority//Interrupt Priority Control Register
IFS0bits.INT1IF= 0; // clear INT0 flag//Interrupt Flag Status Register.
IEC0bits.INT1IE = 1; // enable INT0 interrupt//Interrupt Enable Control Register

INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
INTEnableInterrupts();
}

