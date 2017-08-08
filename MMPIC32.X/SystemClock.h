/* 
 * File:   SystemClock.h
 * Author: optimus
 *
 * Created on 7 de agosto de 2017, 22:47
 */

#ifndef SYSTEMCLOCK_H
#define	SYSTEMCLOCK_H

#ifdef	__cplusplus
extern "C" {
#endif

    

#if defined (__PIC32MX__)
		#include <plib.h>
                    #include <p32xxxx.h>
                    
		/*	Define the hardware platform to use	*/

		#define PIC32MX360			//use PIC32MX360F512L MCU option
		
		// Specific to PIC32MX processor
		#define	GetSystemClock()			(80000000ul)         	// 8 MHz/2 x 20 PLL -or- 12MHz/3 x 20 PLL
		#define	GetPeripheralClock()		GetSystemClock()		//FPBDIV = DIV_1
		#define	GetInstructionClock()		(GetSystemClock())

	#endif

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEMCLOCK_H */

