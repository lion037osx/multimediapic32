/***********************************************************************
 * File:   Primitive.h
 * Author: lion037osx
 *
 * Update on 2 de agosto de 2017, 12:11
 ************************************************************************/


#ifndef PRIMITIVE_H
#define	PRIMITIVE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <GenericTypeDefs.h>
    
#define GFX_FONT_SPACE const

#define FLASH_BYTE  const BYTE
#define FLASH_WORD  const WORD
#define FLASH_DWORD const DWORD

typedef enum
{
	FLASH         = 0x0000,                 // internal flash
	EXTERNAL      = 0x0001,                 // external memory
	FLASH_JPEG    = 0x0002,                 // internal flash
	EXTERNAL_JPEG = 0x0003,                 // external memory
	RAM           = 0x0004,                 // RAM 
	EDS_EPMP      = 0x0005,                 // memory in EPMP, base addresses are 
                                            // are set in the hardware profile

	IMAGE_MBITMAP = 0x0000,                 // data resource is type Microchip bitmap
	IMAGE_JPEG    = 0x0100,                 // data resource is type JPEG

    COMP_NONE     = 0x0000,                 // no compression  
	COMP_RLE      = 0x1000,                 // compressed with RLE
	COMP_IPU      = 0x2000,                 // compressed with DEFLATE (for IPU)
} GFX_RESOURCE;


typedef struct
{
    GFX_RESOURCE  type;                     // must be FLASH
    GFX_FONT_SPACE char    *address;                 // font image address in FLASH
} FONT_FLASH;

/*********************************************************************
* Overview: Structure describing the bitmap header.
*
*********************************************************************/
typedef struct
{
    BYTE        compression;                // Compression setting 
    BYTE        colorDepth;                 // Color depth used
    SHORT       height;                     // Image height
    SHORT       width;                      // Image width
} BITMAP_HEADER;


typedef struct
{
    WORD         width;                       // Parital Image width
    WORD         height;                      // Partial Image height
    SHORT        xoffset;                     // xoffset of image 
    SHORT        yoffset;                     // yoffset of image 
} PUTIMAGE_PARAM;

typedef struct
{
    GFX_RESOURCE type;                      // must be FLASH
    FLASH_BYTE   *address;                  // image address in FLASH
} IMAGE_FLASH;

typedef struct
{
    BYTE        fontID;                     // User assigned value
    BYTE        extendedGlyphEntry : 1;     // Extended Glyph entry flag. When set font has extended glyph feature enabled.
    BYTE        res1               : 1;     // Reserved for future use  (must be set to 0)
    BYTE        bpp                : 2;     // Actual BPP = 2<sup>bpp</sup>  
                                            //   - 0 - 1 BPP
                                            //   - 1 - 2 BPP
                                            //   - 2 - 4 BPP
                                            //   - 3 - 8 BPP
    BYTE        orientation        : 2;     // Orientation of the character glyphs (0,90,180,270 degrees)
                                            //   - 00 - Normal
                                            //   - 01 - Characters rotated 270 degrees clockwise
                                            //   - 10 - Characters rotated 180 degrees
                                            //   - 11 - Characters rotated 90 degrees clockwise
                                            // Note: Rendering DO NOT rotate the characters. The table contains rotated characters
                                            //       and will be rendered as is. 
    BYTE        res2               : 2;     // Reserved for future use (must be set to 0).
    WORD        firstChar;                  // Character code of first character (e.g. 32).
    WORD        lastChar;                   // Character code of last character in font (e.g. 3006).
    WORD        height;                     // Font characters height in pixels. 
} FONT_HEADER;


//typedef unsigned char           BYTE;                           /* 8-bit unsigned  */
//typedef unsigned short int      WORD;                           /* 16-bit unsigned */
//typedef unsigned long           DWORD;                          /* 32-bit unsigned */


#ifdef	__cplusplus
}
#endif

#endif	/* PRIMITIVE_H */

