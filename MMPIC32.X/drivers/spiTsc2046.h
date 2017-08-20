/* 
 * File:   spi.h
 * Author: optimus
 *
 * Created on 8 de agosto de 2017, 16:05
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

//#define SPI_SCK_TRIS      TRISGbits.TRISG6
//#define SPI_SDO_TRIS      TRISGbits.TRISG8
//#define SPI_SCK_TRIS      TRISGbits.TRISG6
//#define SPI_SDO_TRIS      TRISGbits.TRISG8
//#define SPI_CS_TRIS       TRISBbits.TRISB9
    
//OUT_PUTS
#define TOUCH_SCREEN_CS_TRIS       SPI_CS_TRIS
#define TOUCH_SCREEN_CS_LAT        SPI_CS_LAT
#define TOUCH_SCREEN_CS        SPI_CS 

#define TOUCH_SCREEN_SCK_TRIS      SPI_SCK_TRIS
#define TOUCH_SCREEN_SDO_TRIS      SPI_SDO_TRIS

#define TSC_SCK_TRIS      SPI_SCK_TRIS
#define TSC_SDO_TRIS      SPI_SDO_TRIS
#define TSC_CS_TRIS       SPI_CS_TRIS

//define input
#define TOUCH_SCREEN_SDI_TRIS      TRISGbits.TRISG7
#define TSC_SDI_TRIS      TRISGbits.TRISG7

#define TOUCH_SCREEN_SCK      PORTGbits.RG6
#define TOUCH_SCREEN_SDO      PORTGbits.RG8
#define TOUCH_SCREEN_SDI      PORTGbits.RG7    

#define TOUCH_SCREEN_SCK_LAT      LATGbits.LATG6
#define TOUCH_SCREEN_SDO_LAT      LATGbits.LATG8    
#define TOUCH_SCREEN_SDI_LAT      LATGbits.LATG7    

//#define TS_CS  TOUCH_SCREEN_CS    
#define TS_CS  TOUCH_SCREEN_CS_LAT

//#define TS_SCK      TOUCH_SCREEN_SCK
#define TS_SCK TOUCH_SCREEN_SCK_LAT
    
//#define TS_SDO  TOUCH_SCREEN_SDO
#define TS_SDO  TOUCH_SCREEN_SDO_LAT
    
#define TS_SDI TOUCH_SCREEN_SDI

#define CONFIG_SPI2() {TSC_CS_TRIS=0;TSC_SDO_TRIS=0;TSC_SCK_TRIS=0;TSC_SDI_TRIS=1;}

#define CFG_SPI_SDI_DIGITAL() {PORTSetPinsDigitalIn(IOPORT_G,BIT_7);}

#define TSC_CSn_LO() TS_CS=0
#define TSC_CSn_HI() TS_CS=1

#define TSC_SCK_LO() TS_SCK=0
#define TSC_SCK_HI() TS_SCK=1

#define TSC_MOSI_LO() TS_SDO=0
#define TSC_MOSI_HI() TS_SDO=1

#define TSC_SCK_LO()     TS_SCK=0
#define TSC_SCK_HI()     TS_SCK=1

#define TSC_CS_LO() TS_CS=0
#define TSC_CS_HI() TS_CS=1
    
#define TSC_MOSI_HI() TS_SDO=1
#define TSC_MOSI_LO() TS_SDO=0    

void initSpi(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

