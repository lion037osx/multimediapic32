#include "esp8266.h"
//#include "../Uart.h"
#include <GenericTypeDefs.h>
#include "../HardwareProfile.h"

void delay(int time_ms){

    while(time_ms--);
   // DelayMs(100);
}

void AT_CMD(char *p){
DEBUG_UART2(p);
DEBUG_UART2("\r\n");
DEBUG_UART1(p);
DEBUG_UART1("\r\n");
//delay(4);
}


void reset_default_esp8266(void){
    AT_CMD("AT+RESTORE");
    delay(3);
}

void disconnectWifiEsp8266(void){
    AT_CMD("AT+CWQAP");//response "WIFI DISCONNECT"
}

void configWifiEsp8266(char* user , char* password){
    
    DEBUG_UART1("AT+CWMODE=1");//response "OK"
    
    //AT_CMD("AT+CWLAP");//wifi list
    delay(3);

    disconnectWifiEsp8266();
        
    //AT_CMD("AT+CWJAP?");//+CWJAP:"tplink","60:e3:27:cd:85:7e",8,-58
    delay(3);
    //AT_CMD("AT+CWQAP");//WIFI DISCONNECT

    
    //AT_CMD("AT+CWJAP=\"mobile\",\"0102030405\"" );
    
    DEBUG_UART2("AT+CWJAP=\"");
    DEBUG_UART2(user);
    DEBUG_UART2("\",\"");
    DEBUG_UART2(password);
    DEBUG_UART2("\"\r\n");

    DEBUG_UART1("AT+CWJAP=\"");
    DEBUG_UART1(user);
    DEBUG_UART1("\",\"");
    DEBUG_UART1(password);
    DEBUG_UART1("\"\r\n");
    delay(12);
    
    //response "AT+CWJAP="tplink","19781986""
    //response "WIFI CONNECTED"
    //response "WIFI GOT IP"
}


void readConfigWifiEsp8266(void){
    AT_CMD("AT+CIFSR");
    delay(2);
    //response "+CIFSR:STAIP,"192.168.1.101" "
    //response "+CIFSR:STAMAC,"18:fe:34:e1:25:3f" "
}

void udpTxEsp8266(void){
    #if defined(__UDP_TRANSMIT__)
    AT_CMD("AT+MDNS=1,\"PIC32_ESP8266\",\"IoT\",80");
    AT_CMD("AT+CIFSR");

    AT_CMD("AT+CIPSTART=?");
    //AT_CMD("AT+CIPSTART=\"UDP\",\"PIC32Esp8266\",80");

    AT_CMD("AT+CIPMUX?");

    AT_CMD("AT+CIPMUX=1");

    AT_CMD("AT+CIPSERVER=1,8080");

    AT_CMD("AT+CIPSTART=4,\"UDP\",\"192.168.1.33\",8080,4445,0");

    AT_CMD("AT+CIPSEND=4,28");

    AT_CMD("<h1>pic32 with esp8266</h1>");
    //AT_CMD("AT+CIPCLOSE");
    #endif
}

void serverTcpClientEsp8266(void){
    #if defined(___SINGLE_CONEXION_TCP_CLIENT__)
    //AT_CMD("AT+CIPMUX=1");

    //AT_CMD("AT+CIPSERVER=1,8080");

    AT_CMD("AT+CIPSTART=\"TCP\",\"192.168.1.33\",8080");//create server 
    delay(2);
    AT_CMD("AT+CIPSEND=4");

    delay(2);
    //AT_CMD("<h1>pic32 with esp8266</h1>");
    UART1Puts("DGFY\r");
    //AT_CMD("AT+CIPCLOSE");
    #endif
}

void SingleServerEsp8266(void){
    #if defined(__CONEX_TO_SINGLE_SERVER__)
    //AT_CMD("AT+CIPMUX=1");

    //AT_CMD("AT+CIPSERVER=1,8080");

    //AT_CMD("AT+CIPSTART=4,\"TCP\",\"192.168.1.33\",8080,4445");//create server 
    AT_CMD("AT+CIPSTART=\"TCP\",\"192.168.1.33\",8080");//create server 
    delay(5);

    DEBUG_UART2("************************CLICK WEB PAGE************************ 192.168.1.36:80 ************************");
    delay(5);
    AT_CMD("AT+CIPMODE=1");
    delay(15);

    AT_CMD("AT+CIPSEND");
    UART1Puts("<h1>pic32 with esp8266</h1>");

    AT_CMD("AT+CIPSTATUS");
    #endif

}


void timeEsp8266(void){
    #if defined(__TIME_LOCAL__)
    //AT_CMD("AT+CIPSNTPCFG=8");
    AT_CMD("AT+CIFSR");
    delay(5);
    AT_CMD("AT+CIPSNTPCFG=1,8,\"cn.ntp.org.cn\",\"ntp.sjtu.edu.cn\",\"us.pool.ntp.org\"");
    delay(10);
    AT_CMD("AT+CIPSNTPTIME?");
    delay(10);
    #endif
}

void muxConnecxionEsp8266(void){
  #if defined(__MUX_CONNEXION__)
    //AT_CMD("ATE1");
    AT_CMD("AT+CWMODE=1");
    AT_CMD("AT+CIPMUX=1");
     //AT_CMD("AT+CIUPDATE");
    AT_CMD("AT+CIPSERVER=1,80");
    delay(3);
    AT_CMD("AT+CIPSTATUS");
    AT_CMD("AT+CIPDINFO=1");
    //AT_CMD("AT+CIPSTART=0,\"TCP\",\"192.168.4.1\",8080");
    //delay();delay();delay();delay();delay();delay();delay();delay();delay();
    UART2PrintString("************************CLICK WEB PAGE************************ 192.168.1.36:80 ************************\r\n");
    //delay(5);

    delay(10);
    //delay(5);
    static int length;
    static char string_cmd[40];
    length=strlen(html1);
    sprintf(string_cmd,"AT+CIPSEND=0,%d",length);
    AT_CMD(string_cmd);
    delay(3);
    DEBUG_UART1(html1);

    //AT_CMD("AT+CIPSEND=0,27");
    //UART1PrintString("<h1>pic32 with esp8266</h1>");
    //UART1PrintString("123456789012345678901234567");
    delay(3);
    AT_CMD("AT+CIPCLOSE=0");
    #endif
}


void wifiList(void){
    AT_CMD("AT+CWMODE=1\r\n");
    delay(1);
    AT_CMD("AT+CWLAP\r\n");
    
//+CWLAP:(3,"tplink",-57,"60:e3:27:cd:85:7e",8,-7,0)

//+CWLAP:(2,"El Panta",-90,"00:22:6b:48:0f:cb",6,-24,0)    
}

void initESP8266(void){
#ifdef __ESP8266__    
    AT_CMD("AT+RST");
    AT_CMD("ATE0");//response "OK"
    AT_CMD("AT+CWQAP");//response "WIFI DISCONNECT"
    AT_CMD("AT+CWMODE=1");//response "OK"
    AT_CMD("AT+GMR");
    configWifiEsp8266("mobile","0102030405");
    //configWifiEsp8266("tplink","19781986");
    readConfigWifiEsp8266();    
    //udpTxEsp8266();
    //serverTcpClientEsp8266();
    SingleServerEsp8266();
    //timeEsp8266();    
    //muxConnecxionEsp8266();  
#endif
}
