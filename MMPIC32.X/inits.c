#include "SystemClock.h"
#include "Uart.h"
#include "ConfigHardware.h"
#include "Graphics/Ssd1963.h"
#include "Graphics/Colors.h"
#include "interrupts.h"
#include <plib.h>

void configInterruptUart(void){

 //UARTConfigure(UART2, UART_ENABLE_PINS_TX_RX_ONLY);
  //UARTSetFifoMode(UART2, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
  //UARTSetLineControl(UART2, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
  //UARTSetDataRate(UART2, GetPeripheralClock(), DESIRED_BAUDRATE);
  //UARTEnable(UART2, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

  // Configure UART2 RX Interrupt
  INTEnable(INT_SOURCE_UART_RX(UART2), INT_ENABLED);
  INTSetVectorPriority(INT_VECTOR_UART(UART2), INT_PRIORITY_LEVEL_2);
  INTSetVectorSubPriority(INT_VECTOR_UART(UART2), INT_SUB_PRIORITY_LEVEL_0);
}

void inits(void){
DDPCONbits.JTAGEN = 0;	//disable the JTAG port
SYSTEMConfigPerformance(GetSystemClock());
ConfigInterrupts();
ConfigBackligth();
ConfigHardwareLeds();
ConfigClearAllLeds();
ConfigButtonRB4();
UARTInit();
configInterruptUart();
ResetDevice();//graphics function
_color=COLOR_BACKGROUND;
ClearDevice();
BACKLIGTH=1;

initClock();


}