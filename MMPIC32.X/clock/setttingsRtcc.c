
#include "setttingsRtcc.h"
#include "ds1307rtcc.h"
#include <plib.h>
//#include "../Uart.h"
#include "../ConfigHardware.h"
#include "../typedefSettings.h"
//#include "../DrawText.h"
#include "../SystemClock.h"
//#include "../DrawGraphics.h"
#include "../HardwareProfile.h"
#include "../Draw/DrawGraphics.h"


extern BYTE strGet[32];
void ack_i2c1(void){
IdleI2C1();
}

void no_ack_i2c1(void){
IdleI2C1();
}

void sram_byte_write_i2c1(UINT8 address,UINT8 data ){
    StartI2C1();	        //Send the Start Bit
    IdleI2C1();
    MasterWriteI2C1(ADDR_RTCC_WRITE );     
    ack_i2c1();
    MasterWriteI2C1(address);    
    ack_i2c1();
    MasterWriteI2C1(data);
    ack_i2c1();
    StopI2C1();	        //Send the Stop condition
    IdleI2C1();	
}

UINT8 current_address_read(void ){
static UINT8 rtcc_buf=0x00;

    StartI2C1();	  
    ack_i2c1();
    MasterWriteI2C1(ADDR_RTCC_READ);       
    ack_i2c1();
    rtcc_buf=MasterReadI2C1();  
    ack_i2c1();
    StopI2C1();	
    ack_i2c1();
    return (rtcc_buf);
}


UINT8 read_buff_rtcc(UINT8 address){
static UINT8 buff;

    StartI2C1();	
    IdleI2C1();

    MasterWriteI2C1(ADDR_RTCC_WRITE);       
    ack_i2c1();   

    MasterWriteI2C1(address);
    ack_i2c1();    

    buff=current_address_read();
    return (buff);
}

UINT8 start_battery_ds1307(void){             // initialization of the I2C RTCC: enables the battery circuit                                     
// START bit is located in the Sec register
                                     // time/date will be set in 'ini_i2c_time()' 

static BYTE day; 				 // local variable (stores the RTCC DAY register)     
static BYTE state_battery;
day = read_buff_rtcc(ADDR_DAY); 		 // read day + OSCON bit   
state_battery=read_buff_rtcc(VBATEN);
sram_byte_write_i2c1(ADDR_DAY,day|VBATEN);
if(state_battery)return state_battery;
return 0;
}	 // enable the battery back-up  


void set_time(void){             // initialization of time/date vars on the I2C RTCC
 static BYTE day;   				 // local variable (stores the RTCC DAY register) 
 static BYTE str[20];
 
 day=read_buff_rtcc(OSCON);
   // sprintf(str,"debug OSCON:%d\r\n",day);
    UARTPutString(str);
    
day = read_buff_rtcc(ADDR_DAY);   		 // read day + OSCON bit 
if((day&OSCON)==OSCON)return;            // if oscillator = already running, do nothing. 
else{                                // if oscillator = not running, set time/date(arbitrary)
	WRITE_RTCC(ADDR_YEAR,0x17);         // initialize YEAR  register : (20)11           
	WRITE_RTCC(ADDR_MNTH,0x08);   	     // initialize MONTH register : november   
	WRITE_RTCC(ADDR_DATE,0x09);   	     // initialize DATE  register : date = 01  
	WRITE_RTCC(ADDR_HOUR,0x01);   	     // initialize HOUR  register : hour = 00  
	WRITE_RTCC(ADDR_MIN,0x15) ;   	     // initialize MIN   register : min  = 00  
	WRITE_RTCC(ADDR_SEC,START_32KHZ);
	}
//return;
} // init SEC register and start the 32khz oscillator 
 
void print_time(UINT8 tmp,char *str_tmp){
static UINT8 time=0;
static char str[20];  
static UINT dec,uni;
    time=read_buff_rtcc(tmp);
    dec =(UINT) ((time>>4)&0x07)*10;
    uni=(UINT)0x0F&time;
#ifdef __DEBUG_CLOCK__
    UARTPutString(str_tmp);
    sprintf(str,"  %d",dec+uni);
    UARTPutString(str);
    UARTPutString("\r\n");
#endif    
//return;
}

MCP79401 get_time(void)
{
static MCP79401 rtcc;

    rtcc.year=read_buff_rtcc(ADDR_YEAR);      
    rtcc.month=read_buff_rtcc(ADDR_MNTH);   	 
    rtcc.date=read_buff_rtcc(ADDR_DATE);   
    rtcc.hour=read_buff_rtcc(ADDR_HOUR); 
    rtcc.min=read_buff_rtcc(ADDR_MIN) ;   	   
    rtcc.sec=read_buff_rtcc(ADDR_SEC);
return rtcc;
}

MCP79401 puts_uart_time(void)
{
static MCP79401 rtcc;
static BYTE str[60];

rtcc.year=read_buff_rtcc(ADDR_YEAR);      
rtcc.month=read_buff_rtcc(ADDR_MNTH);   	 
rtcc.date=read_buff_rtcc(ADDR_DATE);   
rtcc.hour=read_buff_rtcc(ADDR_HOUR); 
rtcc.min=read_buff_rtcc(ADDR_MIN) ;   	   
rtcc.sec=read_buff_rtcc(ADDR_SEC);

#ifdef __DEBUG_CLOCK__
    sprintf(str,"date 20%X/%d%d/%d%d",rtcc.year,(rtcc.month>>4)&0x7,rtcc.month&0xf,(rtcc.date>>4)&0x7,rtcc.date&0xf);
    UARTPutString(str);
    sprintf(str,"  %d%d:%d%d:%d%d\r\n",(rtcc.hour>>4)&0x7,rtcc.hour&0xf,(rtcc.min>>4)&0x7,rtcc.min&0xf,(rtcc.sec>>4)&0x7,rtcc.sec&0xf);
    UARTPutString(str);
#endif
return rtcc;    
}

void initClock(void){    
static UINT8 stat;    
static char str[32];
init_sda_scl();
OpenI2C1(I2C_EN|I2C_ACK_EN,BRG_VAL);
I2CSetFrequency(I2C1,GetSystemClock(),I2C_CLOCK_FREQ);

stat=start_battery_ds1307();
sprintf(str,"value battery: %d \r\n",stat);
UARTPutString(str);
stat=compare_rtcc();
if(stat)UARTPutString("OSC success!\r\n");
//return;
}

UINT8 func_clock(void){
static UINT8 time,tmp;
static MCP79401 rtccTmp;
static MCP79401 rtcc;

rtcc=get_time();
time=rtcc.sec;
//time=read_buff_rtcc(ADDR_SEC);
    if(time!=tmp)
    {
        rtcc=puts_uart_time();
        if((rtcc.min)!=(rtccTmp.min))
        {
            draw_clock(rtcc);
            rtccTmp=rtcc;
        }
        tmp=time;
        return TRUE;
    }
return FALSE;
}


UINT8 compare_rtcc(void){
MCP79401 rtcc_set,rtcc_read;
static char str[20];
static BYTE day;   				 // local variable (stores the RTCC DAY register) 

day=read_buff_rtcc(ADDR_DAY); 

rtcc_set.year=0x17;
rtcc_set.month=0x01;
rtcc_set.date=0x01;
rtcc_set.hour=0x00;
rtcc_set.min=0x00;

rtcc_read=get_time();
//rtcc_read.day= read_rtcc(ADDR_DAY);
    if((day&OSCON)==OSCON){
    #ifdef __DEBUG_CLOCK__
        return TRUE;
    #endif
    }
    else
    {
    #ifdef __DEBUG_CLOCK__
        UARTPutString("Settings clock\r\n");

        sprintf(str,"year:0x%X\r\n",rtcc_read.year);
        UARTPutString(str);
        sprintf(str,"month:0x%X\r\n",rtcc_read.month);
        UARTPutString(str);
        sprintf(str,"day:0x%X\r\n",rtcc_read.date);
        UARTPutString(str);
        sprintf(str,"hour:0x%X\r\n",rtcc_read.hour);
        UARTPutString(str);
        sprintf(str,"min:0x%X\r\n",rtcc_read.min);
        UARTPutString(str);
    #endif
        set_time();
    }
puts_uart_time();


return FALSE;
}

BYTE* str_month(BYTE tmp){
static UINT convert;
static BYTE *str;
convert=0;
if((tmp>>4)&0x7){
convert=((tmp>>4)&0x7)*10;
}
convert=convert+(tmp&0xF);
    switch(convert){
        case JANUARY:
        sprintf(str,"JANUARY");
        break;
        case FEBRUARY:
        sprintf(str,"FEBRUARY");
        break;
        case MARCH:
        sprintf(str,"MARCH");
        break;
        case APRIL:
        sprintf(str,"APRIL");
        break;
        case MAY:
        sprintf(str,"MAY");
        break;
        case JUNE:
        sprintf(str,"JUNE");
        break;
        case JUL:
        sprintf(str,"JUL");
        break;
        case AUGUST:
        sprintf(str,"AUGUST");
        break;
        case SETEMBER:
        sprintf(str,"SETEMBER");
        break;
        case OCTOBER:
        sprintf(str,"OCTOBER");
        break;
        case NOVEMBER:
        sprintf(str,"NOVEMBER");
        break;
        case DECEMBER:
        sprintf(str,"DECEMBER");
        break;
        default:
        break;
    }    
return (str);    
}


void settingsClock(MCP79401 clkTmp){
    WRITE_RTCC(ADDR_YEAR,clkTmp.year);     
	WRITE_RTCC(ADDR_MNTH,clkTmp.month);
	WRITE_RTCC(ADDR_DATE,clkTmp.date);
	WRITE_RTCC(ADDR_HOUR,clkTmp.hour);
	WRITE_RTCC(ADDR_MIN,clkTmp.min) ;
	WRITE_RTCC(ADDR_SEC,START_32KHZ);
}

void setClockUart(void){
MCP79401 clkTmp;
//strGet   @date 081200222017
clkTmp.year=((strGet[16]-48)<< 4 ) | strGet[17]-48;// 1char = 49c  : '7' char = 55d
clkTmp.month=((strGet[6]-48)<< 4 ) | strGet[7]-48;
clkTmp.date=((strGet[8]-48)<< 4 ) | strGet[9]-48;
clkTmp.hour=((strGet[10]-48)<< 4 ) | strGet[11]-48;
clkTmp.min=((strGet[12]-48)<< 4 ) |strGet[13]-48;


settingsClock(clkTmp);
}