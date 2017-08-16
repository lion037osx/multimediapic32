/* 
 * File:   Colors.h
 * Author: optimus
 *
 * Created on 3 de agosto de 2017, 11:12
 */

#ifndef COLORS_H
#define	COLORS_H

#ifdef	__cplusplus
extern "C" {
#endif


#define BLACK               RGB565CONVERT(0,    0,      0)
#define BRIGHTBLUE          RGB565CONVERT(0,    0,      255)
#define BRIGHTGREEN         RGB565CONVERT(0,    255,    0)
#define BRIGHTCYAN          RGB565CONVERT(0,    255,    255)
#define BRIGHTRED           RGB565CONVERT(255,  0,      0)
#define BRIGHTMAGENTA       RGB565CONVERT(255,  0,      255)
#define BRIGHTYELLOW        RGB565CONVERT(255,  255,    0)
#define BLUE                RGB565CONVERT(0,    0,      128)
#define GREEN               RGB565CONVERT(0,    128,    0)
#define CYAN                RGB565CONVERT(0,    128,    128)
#define RED                 RGB565CONVERT(128,  0,      0)
#define MAGENTA             RGB565CONVERT(128,  0,      128)
#define BROWN               RGB565CONVERT(255,  128,    0)
#define LIGHTGRAY           RGB565CONVERT(128,  128,    128)
#define DARKGRAY            RGB565CONVERT(64,   64,     64)
#define LIGHTBLUE           RGB565CONVERT(128,  128,    255)
#define LIGHTGREEN          RGB565CONVERT(128,  255,    128)
#define LIGHTCYAN           RGB565CONVERT(128,  255,    255)
#define LIGHTRED            RGB565CONVERT(255,  128,    128)
#define LIGHTMAGENTA        RGB565CONVERT(255,  128,    255)
#define YELLOW              RGB565CONVERT(255,  255,    128)
#define WHITE               RGB565CONVERT(255,  255,    255)
#define SKY               RGB565CONVERT(200,  255,    255)
#define CLOUD               RGB565CONVERT(254,254,254)
                            
#define GRAY0       	    RGB565CONVERT(224,  224,    224)
#define GRAY1         	    RGB565CONVERT(192,  192,    192)   
#define GRAY2               RGB565CONVERT(160,  160,    160)   
#define GRAY3               RGB565CONVERT(128,  128,    128)
#define GRAY4               RGB565CONVERT(96,   96,     96)
#define GRAY5               RGB565CONVERT(64,   64,     64)
#define GRAY6	            RGB565CONVERT(32,   32,     32)

#define BLUE_BG    0x2167//RGB565CONVERT(0x6721);
    
    
//#define COLOR_BACKGROUND RGB565CONVERT(254,254,254)
  #define COLOR_BACKGROUND   BLUE_BG
//#define COLOR_BACKGROUND WHITE
    
#define COLOR_FRONT_ICON GRAY2  
#define COLOR_BACKGROUND_ICON COLOR_BACKGROUND
    
/********************   Set colors Icons    *************************/
#define COLOR_ICON_OFF      GRAY5// 0x32AE//color SpaceBackGround  0x32AE
#define COLOR_ICON_ON BRIGHTGREEN
    
#define COLOR_FRONT_TEXT GRAY1
    
#define COLOR_TOOL_BAR GRAY5

#define COLOR_FONT_CLOCK GRAY1
#define COLOR_BACKGROUND_CLOCK  0x32AE//color SpaceBackGround  0x32AE//COLOR_TOOL_BAR
    
#define COLOR_FRONT_BUTTON  WHITE  
#define COLOR_BACK_BUTTON WHITE  
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* COLORS_H */

