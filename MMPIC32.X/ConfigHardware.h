/* 
 * File:   ConfigHardware.h
 * Author: optimus
 *
 * Created on 7 de agosto de 2017, 22:46
 */

#ifndef CONFIGHARDWARE_H
#define	CONFIGHARDWARE_H

#ifdef	__cplusplus
extern "C" {
#endif

/************************************     Config TRIS UART2  PIC32MX  ***********************************/                                           
#define TX_TRIS	TRISFbits.TRISF5
#define RX_TRIS TRISFbits.TRISF4

    
/**************************************        Config outputs Pins      ****************************************/    

#define HardwareConfigButtonInit()      {TRISBbits.TRISB4=1;\
                                        TRISAbits.TRISA7=1;\
                                        TRISDbits.TRISD6=1;\
                                        TRISDbits.TRISD7=1;\
                                        TRISDbits.TRISD13=1;\
                                        }

#define GetHWButtonProgram1()   PORTAbits.RA7

#define GetHWButtonProgram2()   PORTDbits.RD6

#define GetHWButtonProgram3()   PORTDbits.RD7

#define GetHWButtonProgram4()   PORTDbits.RD13

#define GetHWButtonProgram5()   PORTB4bits.RB4

//#define HardwareOuputsAllTrisA() {TRISAbits.TRISA0=0;\
//TRISAbits.TRISA1=0;TRISAbits.TRISA2=0;TRISAbits.TRISA3=0;\
//TRISAbits.TRISA4=0;TRISAbits.TRISA5=0;TRISAbits.TRISA6=0;TRISAbits.TRISA7=0;}
    
/*Config  pin backligth */
#define BACKLIGTH PORTDbits.RD0 
#define  Back_ligth_off() {BACKLIGTH=0;}
#define ConfigBackligth() {TRISDbits.TRISD0=0;}    
    
//#define get_portb4() LATBbits.LATB4
#define get_portb4() PORTBbits.RB4

#define PUSH 0
/*Config Led  */

//#ifdef __CONFIG_LEDS_PCB__    
#define LED_RA0 PORTAbits.RA0
#define LED_RA1 PORTAbits.RA1
#define LED_RA2 PORTAbits.RA2
#define LED_RA3 PORTAbits.RA3
//#endif    
//#define LED_RA4 PORTAbits.RA4
//#define LED_RA5 PORTAbits.RA5
//#define LED_RA6 PORTAbits.RA6
//#define LED_RA7 PORTAbits.RA7    
#define ConfigHardwareLeds() {TRISAbits.TRISA0=0;TRISAbits.TRISA1=0;TRISAbits.TRISA2=0;TRISAbits.TRISA3=0;}

#define ConfigClearAllLeds()    {LED_RA0=LED_RA1=LED_RA2=LED_RA3=LOW;}

    
#define configOutCsSst25() {TRISEbits.TRISE9=0;}

#define LED_RE9 PORTEbits.RE9

#define  HIGH 1
#define LOW 0 
    
#define Fsck	100000
#define BRG_VAL 	((GetPeripheralClock()/2/Fsck)-2)

#define I2C_CLOCK_FREQ              100000
    
// EEPROM Constants
#define EEPROM_I2C_BUS              I2C1
#define EEPROM_ADDRESS              0x50        // 0b1010000 Serial EEPROM address

#define I2C_BUS              I2C1
#define ADDRESS              0x50        // 0b1010000 Serial EEPROM address
        
//Config PIN OUTS SDA SCL    
#define TRIS__RG3_SDA TRISGbits.TRISG3
#define TRIS__RG2_SCL TRISGbits.TRISG2

#define init_sda_scl()    {TRISGbits.TRISG2=1;TRISGbits.TRISG3=1;}
    
#define TPI2CCON    I2C1CON
#define TPCONbits   I2C1CONbits
#define TPI2CSTAT   I2C1STAT
#define TPSTATbits  I2C1STATbits
#define TPI2CMSK     I2C1MSK
#define TPI2CRCV     I2C1RCV
#define TPI2CTRN     I2C1TRN
#define TPI2CADD     I2C1ADD
#define TPI2CBRG    I2C1BRG

#define C_TP_ADDR   0x3E
#define C_TP_READ   0x7D
#define C_TP_WRITE  0x7C    
    
#define LIS_I2C_ADDRESS             0x19
#define LIS_ID_REG                  0x0F
#define LIS_CNTRL_REG1              0x20 


    
#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGHARDWARE_H */

