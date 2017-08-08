/* 
 * File:   tsc2046.h
 * Author: optimus
 *
 * Created on 8 de agosto de 2017, 16:04
 */

#ifndef TSC2046_H
#define	TSC2046_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <GenericTypeDefs.h>
#include <stdbool.h>

// For ESI unit, at least, we swap the x,y axis to better match
// the underlying LCD controller's view of things.
#define TSC_SWAP 1    

// A "base" command for us is 0x83 : Start bit set; PenIRQ disabled, ref on, adc on.
// To that, we select the appropriate channel, and diff/single-ended mode:
//                 (Base | Chnl | Single/Diff mode)
#define TSC_TEMP0  (0x83 | 0x00 | 0x00)
#define TSC_Y      (0x83 | 0x10 | 0x04)
#define TSC_VBAT   (0x83 | 0x20 | 0x00)
#define TSC_Z1     (0x83 | 0x30 | 0x04)
#define TSC_Z2     (0x83 | 0x40 | 0x04)
#define TSC_X      (0x83 | 0x50 | 0x04)
#define TSC_AUX    (0x83 | 0x60 | 0x00)
#define TSC_TEMP1  (0x83 | 0x70 | 0x00)


UINT16 getCmdTsc2046(UINT8 cmd);
bool getCoordTsc2046(UINT16 *x ,UINT16 *y);
void setOutputsTsc2046(void);





#ifdef	__cplusplus
}
#endif

#endif	/* TSC2046_H */

