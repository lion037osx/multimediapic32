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

    



UINT16 getCmdTsc2046(UINT8 cmd);
bool getCoordTsc2046(UINT16 *x ,UINT16 *y);
void setOutputsTsc2046(void);





#ifdef	__cplusplus
}
#endif

#endif	/* TSC2046_H */

