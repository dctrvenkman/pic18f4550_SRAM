/* 
 * File:   SRAM.h
 * Author: root
 *
 * Created on August 26, 2012, 7:27 PM
 */

#ifndef SRAM_H
#define	SRAM_H

// Pin Definitions
#define SRAM_ADDR_0     PORTDbits.RD0
#define SRAM_ADDR_1     PORTDbits.RD1
#define SRAM_ADDR_2     PORTDbits.RD2
#define SRAM_ADDR_3     PORTDbits.RD3
#define SRAM_ADDR_4     PORTDbits.RD4
#define SRAM_ADDR_5     PORTDbits.RD5
#define SRAM_ADDR_6     PORTDbits.RD6
#define SRAM_ADDR_7     PORTDbits.RD7
#define SRAM_ADDR_8     PORTAbits.RA0
#define SRAM_ADDR_9     PORTAbits.RA1
#define SRAM_ADDR_10    PORTAbits.RA2
#define SRAM_ADDR_11    PORTAbits.RA3
#define SRAM_ADDR_12    PORTAbits.RA4
#define SRAM_ADDR_13    PORTAbits.RA5
#define SRAM_ADDR_14    PORTCbits.RC0
#define SRAM_ADDR_15    PORTCbits.RC1
#define SRAM_ADDR_16    PORTCbits.RC2
// RC4 and RC5 Only inputs so can't be used
#define SRAM_ADDR_17    PORTCbits.RC4
#define SRAM_ADDR_18    PORTCbits.RC5

//D[0:8] = PORTB[0:8]
#define SRAM_DATA_PORT  PORTB

//OE = RE0
#define SRAM_OE         PORTEbits.RE0

//WE = RE1
#define SRAM_WE         PORTEbits.RE1

//CE = RE2
#define SRAM_CE         PORTEbits.RE2


#define SRAM_DELAY_US      100


#ifdef	__cplusplus
extern "C" {
#endif


void SRAM_Setup_Pins();
unsigned char SRAM_Read(unsigned long int addr);
void SRAM_Write(unsigned long int addr, unsigned char data);
void SRAM_Print(unsigned int addr, unsigned int count);

#ifdef	__cplusplus
}
#endif

#endif	/* SRAM_H */

