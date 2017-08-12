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
    
    
#ifdef __ENABLE_DRIVERS__
    #define __PIC32MX360__
    #define __SPI1__
    #define __SPI2__    
#endif
    
#ifdef __ENABLE_INTERRUPTS__
    #define __TIMER1__
    #define __INTERRUPT_EXTERNAL1__
    //#define __TIMER2__    
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
    
#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

