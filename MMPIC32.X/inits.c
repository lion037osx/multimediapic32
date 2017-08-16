#include "SystemClock.h"
#include "Uart.h"
#include "ConfigHardware.h"
#include "Graphics/Ssd1963.h"
#include "Graphics/Colors.h"
#include "interrupts.h"
#include <plib.h>
#include "HardwareProfile.h"
#include "Draw/DrawLogo.h"


void configInterruptUart(void){

 //UARTConfigure(UART2, UART_ENABLE_PINS_TX_RX_ONLY);
  //UARTSetFifoMode(UART2, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
  //UARTSetLineControl(UART2, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
  //UARTSetDataRate(UART2, GetPeripheralClock(), DESIRED_BAUDRATE);
  //UARTEnable(UART2, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
#ifdef __UART1__    
    INTEnable(INT_SOURCE_UART_RX(UART1), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(UART1), INT_PRIORITY_LEVEL_1);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART1), INT_SUB_PRIORITY_LEVEL_0);
#endif   
    
#ifdef __UART2__
  // Configure UART2 RX Interrupt
    INTEnable(INT_SOURCE_UART_RX(UART2), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(UART2), INT_PRIORITY_LEVEL_2);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART2), INT_SUB_PRIORITY_LEVEL_0);
#endif 
}


void configUart(void){

#ifdef __UART1__
    UART1Init();
#endif
    #ifdef __UART2__
    UARTInit();
#endif
    configInterruptUart();
}



void inits(void){
    DDPCONbits.JTAGEN = 0;	//disable the JTAG port
    SYSTEMConfigPerformance(GetSystemClock());
    Back_ligth_off();
    ConfigInterrupts();
    
    configUart();
    INTEnableInterrupts();
    ConfigBackligth();
    ConfigHardwareLeds();
    ConfigClearAllLeds();

    ResetDevice();//graphics function
    
    //_color=COLOR_BACKGROUND;
    //ClearDevice();
    
    showLogo();
    
    BACKLIGTH=1;
    DelayMs(4000);  
  
    initESP8266();
    ConfigButtonRB4();      
    initClock();  
}