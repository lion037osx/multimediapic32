/* 
 * File:   esp8266.h
 * Author: optimus
 *
 * Created on 13 de agosto de 2017, 12:28
 */

#ifndef ESP8266_H
#define	ESP8266_H

#ifdef	__cplusplus
extern "C" {
#endif
#define __TELNET__
    
//#define __MUX_CONNEXION__    
//#define __TIME_LOCAL__
#ifdef __TELNET__    
    #define __CONEX_TO_SINGLE_SERVER__    
#endif    
//#define ___SINGLE_CONEXION_TCP_CLIENT__
//#define __UDP_TRANSMIT__     
    
#define START 1
#define STOP 0    
    
#define DEBUG_UART2 UARTPutString
#define DEBUG_UART1 UART1Puts   
    
void AT_CMD(char *p);
void initESP8266(void);


enum{
    ESP8266_INITS,
    ESP8266_INFO,
    ESP8266_START_SERVER,
    ESP8266_WIFI_LIST,
    ESP8266_TELNET,
    ESP8266_CFG_WIFI,
    ESP8266_READ_CFG_WIFI,
    ESP8266_DISCONNECT_WIFI,
    ESP8266_RESET_TO_DEFAULTS,
    ESP8266_RESET,
}ESP8266;



#ifdef	__cplusplus
}
#endif

#endif	/* ESP8266_H */

