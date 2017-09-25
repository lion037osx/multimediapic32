#include "dfplayer.h"
#include <string.h>
#include <GenericTypeDefs.h>

unsigned char cmd_next_play2[]={  0x1 , 0x0 , 0x0 , 0x0 };
unsigned char cmd_str_dfp[6];

  
 
void playDfp(void){
static int x;
DWORD checksum;

checksum=0x10000;
//UART1Puts(cmd_play);
//UARTPutString(cmd_play);
//checksum=checksum-

        
UART1PutChar(CMD_START_BYTE_DFP);
UART1PutChar(CMD_VERSION_DFP);
checksum=checksum-CMD_VERSION_DFP;
UART1PutChar(CMD_N_BYTES_DFP);
checksum=checksum-CMD_N_BYTES_DFP;
for(x=0;x<4;x++)
    {
    UART1PutChar(cmd_next_play2[x]);
    checksum=checksum-cmd_next_play2[x];
    }

UART1PutChar((checksum>>8)&0x0000FF);
UART1PutChar(checksum&0x0000FF);
UART1PutChar(CMD_END_DFP);

}



void playFolderDfp(void){
static int x;
DWORD checksum;

checksum=0x10000;
//UART1Puts(cmd_play);
//UARTPutString(cmd_play);
//checksum=checksum-

        
UART1PutChar(CMD_START_BYTE_DFP);

UART1PutChar(CMD_VERSION_DFP);
checksum=checksum-CMD_VERSION_DFP;

UART1PutChar(CMD_N_BYTES_DFP);
checksum=checksum-CMD_N_BYTES_DFP;

UART1PutChar(CMD_FOLDER_DFP);
checksum=checksum-CMD_FOLDER_DFP;

UART1PutChar(0x00);
checksum=checksum-0x00;

UART1PutChar(NAME_FOLDER_DFP);
checksum=checksum-NAME_FOLDER_DFP;

UART1PutChar(NAME_FILE_DFP);
checksum=checksum-NAME_FILE_DFP;

UART1PutChar((checksum>>8)&0x0000FF);
UART1PutChar(checksum&0x0000FF);

UART1PutChar(CMD_END_DFP);

}