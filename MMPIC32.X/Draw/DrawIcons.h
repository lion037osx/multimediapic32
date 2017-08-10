/* 
 * File:   drawIcons.h
 * Author: optimus
 *
 * Created on 6 de agosto de 2017, 00:40
 */

#ifndef DRAWICONS_H
#define	DRAWICONS_H

#ifdef	__cplusplus
extern "C" {
#endif
//#include "System.h"
#include "../TimeDelay.h"
#include "../typedefSettings.h"
//#include "debug.h"
/*
#include "../icons/battery32x32.h"
#include "../icons/check32.h"
#include "../icons/cogs32.h"
#include "../icons/db32.h"
#include "../icons/globe32.h"
#include "../icons/pinmap32.h"
#include "../icons/sun32.h"
#include "../icons/users32.h"
#include "../icons/wrench32.h"    
*/
void draw_icon(WORD start_x ,WORD start_y ,BYTE *bmp ,WORD color);

#ifdef	__cplusplus
}
#endif

#endif	/* DRAWICONS_H */

