/****************************************************************************************
 * File:   settingsRtcc.h
 * Author: leo
 *
 * Created on July 3, 2017, 11:25 PM
 ****************************************************************************************/

#ifndef SETTINGSRTCC_H
#define	SETTINGSRTCC_H

#define __SET_CLOCK__

#ifdef	__cplusplus
extern "C" {
#endif
#include <GenericTypeDefs.h>

typedef struct tyme_clock_t{
    UINT8 year:7;
    UINT8 month:7;
    UINT8 date:7;
    UINT8 hour:7;
    UINT8 min:7;
    UINT8 sec:7;
}RTCC_t;


#define RTCC RTCC_t
#define MCP79401 RTCC_t

    
//void DelayMs(unsigned t);
UINT8 start_battery_ds1307(void);
void set_time(void);
void sram_byte_write_i2c1(BYTE address,BYTE data);
BYTE read_buff_rtcc(BYTE address);
void print_time(BYTE tmp,char *str);
void initClock(void);
UINT8 compare_rtcc(void);
MCP79401 puts_uart_time(void);
MCP79401 get_time(void);
BYTE* str_month(BYTE tmp);
void settingsClock(MCP79401 settings);
void setClockUart(void);


#define WRITE_RTCC sram_byte_write_i2c1

#ifdef	__cplusplus
}
#endif

#endif

