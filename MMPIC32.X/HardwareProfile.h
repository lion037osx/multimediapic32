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
    
    
    
#ifdef __ENABLE_DRIVERS__
#define __PIC32MX360__
#endif
    
    
    
    
#define HEIGHT_SCREEN DISP_VER_RESOLUTION    
#define WIDTH_SCREEN DISP_HOR_RESOLUTION
   
    
/*******************************        Config Debug        ************************************/    
#define __DEBUG_CLOCK__    
#define  DEBUG  UARTPutString
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

