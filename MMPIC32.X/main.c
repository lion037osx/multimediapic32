/*********************************************************************
 ********************************************************************/
#include <plib.h>

//#pragma config FPBDIV = DIV_8
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2	
#pragma config FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL

#include "System.h"

 extern UINT16 flagSetConfig;
 extern BYTE strGet[32];

int main(void){
    inits();     
    run();  
}

#ifdef __INTERRUPT_EXTERNAL1__    
void __ISR(_EXTERNAL_1_VECTOR,IPL7SOFT)  ExtInt1_ISR(void){
    static int flag;
    LED_RA0=1;
    flag=1;
    menumMaster(flag);
    IFS0bits.INT1IF=0;  
}
#endif

#ifdef __TIMER1__

void __ISR(_TIMER_1_VECTOR,IPL6SOFT) Timer1Handler(void)
{
static unsigned int counterTimer1=0;
static unsigned int count=0;   
    if(count>=500){
    updateClock();
    count=0;
    }
count++;
    if(get_portb4()==0)counterTimer1++;
    if(counterTimer1>=1000)
    {
        counterTimer1=0;
        flagSetConfig++;
        LED_RA0=~LED_RA0;
    }

IFS0bits.T1IF = 0;
}
#endif

#ifdef __TIMER2__
void __ISR(_TIMER_2_VECTOR,ipl6AUTO) Timer1Handler(void)
{
    IFS0bits.T2IF = 0;
}
#endif

void __ISR(_UART2_VECTOR, IPL2SOFT) IntUart2Handler(void)
{
static BYTE getTmp[32];
static int x=0;
static int flag_uart=0;
    // Is this an RX interrupt?
  if (INTGetFlag(INT_SOURCE_UART_RX(UART2)))
    {
       if(flag_uart==1)x++;       
      // Echo what we just received.
      getTmp[x]=UARTGetChar();
      if(getTmp[x]==0x40)flag_uart=1;
      if(getTmp[x]==0x7F){
          getTmp[x+1]=0x00;
            flag_uart=0;
            x=0;
            strcpy(strGet,getTmp);
            UARTPutString(getTmp);
            
            setClockUart();
            
            LED_RA3=1;
        }
      // Clear the RX interrupt Flag
      INTClearFlag(INT_SOURCE_UART_RX(UART2));

      // Toggle LED to indicate UART activity
      mPORTAToggleBits(BIT_0);
      
  // We don't care about TX interrupt
  if ( INTGetFlag(INT_SOURCE_UART_TX(UART2)) )
        {
            INTClearFlag(INT_SOURCE_UART_TX(UART2));
        }
    }
}