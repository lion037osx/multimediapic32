/* 
 * File:   HardwareProfile.h
 * Author: optimus
 *
 * Created on 7 de agosto de 2017, 22:39
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define __ENABLE_DRIVERS__
#define __ENABLE_INTERRUPTS__    
//#define __INTERRUPT_EXT_TSC2046__    
    
#ifdef __ENABLE_DRIVERS__
    #define __PIC32MX360__
    #define __SPI1__
#ifdef  __INTERRUPT_EXT_TSC2046__
    #define __SPI2__    
#endif
    #define __ESP8266__
#endif
    
#ifdef __ENABLE_INTERRUPTS__
    #define __TIMER1__
    #ifdef  __INTERRUPT_EXTERNAL_TSC2046__
        #define __INTERRUPT_EXTERNAL1__
    #endif
    //#define __TIMER2__    
#endif 
       
#define USE_SST25_SPI2       
#define SPI_CHANNEL_2_ENABLE         
#define USE_SST25VF016
#define SST25_CS_TRIS TRISDbits.TRISD1  
//#define GFX_EXPLORER16
#define MULTI_MEDIA_BOARD_DM00123
//#define __PIC32MX
#define SST25_SPI_CHANNEL 2    
#define SST25_CS_LAT    LATDbits.LATD1
    
#if defined (USE_SST25VF016)
    #define FLASHInit(initData)             SST25Init(initData);
	#define ChipErase()                     SST25ChipErase();
	#define WriteArray(address, pdata, len) SST25WriteArray(address, pdata, len)
    #define ReadArray(address, pdata, len)  SST25ReadArray(address, pdata, len)
#endif	    
    
#define INPUT 1
#define OUTPUT 0    
#define PUSH 0   
#define BUTTON_TRIS TRISBbits.TRISB4
#define BUTTON_STAT PORTBbits.RB4   
    
    
    
    
    
//#define __MEMORY_FLASH__

#ifdef __MEMORY_FLASH__
  //#define  
#else 
    #define __MEMORY_RAM__
#endif    
    
    
    
///*****************************    ENABLE DRAWS    ***************************///
 #define __DRAW_CLOCK__
//#define __DEBUG__    
    
//#define HEIGHT_SCREEN DISP_VER_RESOLUTION    
//#define WIDTH_SCREEN DISP_HOR_RESOLUTION
#define HEIGHT_SCREEN 272    
#define WIDTH_SCREEN 480
  
    
/*******************************        Config Debug        ************************************/    
#define __DEBUG_CLOCK__    
#define  DEBUG  UARTPutString

#define INPUT 1
#define OUTPUT 0    
    
    
#define __UART1__
#define __UART2__
    
/*******************************************       Config Esp8266         ***********************************************/    
    

#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

