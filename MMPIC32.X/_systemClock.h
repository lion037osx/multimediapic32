/* 
 * File:   sytemClock.h
 * Author: optimus
 *
 * Created on 6 de agosto de 2017, 23:19
 */

#ifndef SYTEMCLOCK_H
#define	SYTEMCLOCK_H

#ifdef	__cplusplus
extern "C" {
#endif


	#if defined (__18CXX)
		#include <p18cxxx.h>

		#define PIC18F24JXXX				//Host to be the companion board with SSD1963 Ultima Rev4.1A
											//Item: Microchip PIC 28-PDIP: part# EVK PIC28PDIP R1.0
		#define	GetSystemClock()			(32000000ul)
		#define	GetPeripheralClock()		(GetSystemClock()/4)
		#define	GetInstructionClock()		(GetSystemClock()/4)
		
	#elif defined (__PIC32MX__)
		#include <plib.h>
                    #include <p32xxxx.h>
                    
		/*	Define the hardware platform to use	*/
	//#define PIC32_STARTER_KIT			//use PIC32 STARTER Kit on MMEVK R1A
		#define PIC32MX_EVK_RD4			//use PIC24/32 EVK RD4 with PIC32MX360F512L MCU option
		
		// Specific to PIC32MX processor
		#define	GetSystemClock()			(80000000ul)         	// 8 MHz/2 x 20 PLL -or- 12MHz/3 x 20 PLL
		#define	GetPeripheralClock()		GetSystemClock()		//FPBDIV = DIV_1
		#define	GetInstructionClock()		(GetSystemClock())
	
/************************************     Config TRIS UART2  PIC32MX  ***********************************/                                           

	#endif	//#if defined (__18CXX)


#ifdef	__cplusplus
}
#endif

#endif	/* SYTEMCLOCK_H */

