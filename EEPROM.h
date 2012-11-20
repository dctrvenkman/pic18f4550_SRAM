/* 
 * File:   EEPROM.h
 * Author: root
 *
 * Created on August 26, 2012, 7:27 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

// Pin Definitions
#define EEPROM_ADDR_0     PORTDbits.RD0
#define EEPROM_ADDR_1     PORTDbits.RD1
#define EEPROM_ADDR_2     PORTDbits.RD2
#define EEPROM_ADDR_3     PORTDbits.RD3
#define EEPROM_ADDR_4     PORTDbits.RD4
#define EEPROM_ADDR_5     PORTDbits.RD5
#define EEPROM_ADDR_6     PORTDbits.RD6
#define EEPROM_ADDR_7     PORTDbits.RD7
#define EEPROM_ADDR_8     PORTAbits.RA0
#define EEPROM_ADDR_9     PORTAbits.RA1
#define EEPROM_ADDR_10    PORTAbits.RA2
#define EEPROM_ADDR_11    PORTAbits.RA3
#define EEPROM_ADDR_12    PORTAbits.RA4
#define EEPROM_ADDR_13    PORTAbits.RA5
#define EEPROM_ADDR_14    PORTCbits.RC0
#define EEPROM_ADDR_15    PORTCbits.RC1
#define EEPROM_ADDR_16    PORTCbits.RC2
// RC4 and RC5 Only inputs so can't be used
#define EEPROM_ADDR_17    PORTCbits.RC4
#define EEPROM_ADDR_18    PORTCbits.RC5

//D[0:8] = PORTB[0:8]
#define EEPROM_DATA_PORT  PORTB
#define EEPROM_DATA_TRIS  TRISB

//OE = RE0
#define EEPROM_OE         PORTEbits.RE0
//WE = RE1
#define EEPROM_WE         PORTEbits.RE1
//CE = RE2
#define EEPROM_CE         PORTEbits.RE2

#define EEPROM_PAGE_SIZE        128

//Assumes page size is power of 2
#define ADDR_TO_PAGE_BASE_ADDR(addr) (addr & (~(EEPROM_PAGE_SIZE - 1)))

#ifdef	__cplusplus
extern "C" {
#endif

void EEPROM_Setup_Pins();
unsigned char EEPROM_Read(unsigned long int addr);
void EEPROM_Write(unsigned long int addr, unsigned char data);
void EEPROM_Print(unsigned int addr, unsigned int count);
void EEPROM_Write_Byte(unsigned long int addr, unsigned char data);
void EEPROM_Write_Page(unsigned long int addr, unsigned char* data);
void EEPROM_Data_Protect_Disable();
void EEPROM_Erase_Chip();
void EEPROM_ID();

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

