#include <stdio.h>
#include "htc_wrapper.h"
#include "system.h"
#include "SRAM.h"

void SRAM_Setup_Pins()
{
    // Set all analog pins to digital I/O
    ADCON1bits.PCFG = 0xf;

    // Disable USB for PORT functionality on RC4 and RC5
    UCONbits.USBEN = 0;
    UCFGbits.UTRDIS = 0;

    // Capture/Compare/PWM off
    CCP1CONbits.CCP1M = 0x0;
    CCP2CONbits.CCP2M = 0x0;

    TRISD = 0x00;   //PORTD[0:7] outputs
    TRISA &= 0xC0;  //PORTA[0:5] outputs
    TRISC &= 0xC0;  //PORTC[0:5] outputs
    TRISB &= 0xFF;  //PORTB[0:7] inputs
    TRISE &= 0xF8;  //PORTE[0:2] outputs

    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0x7;
}

inline void setDataLines(unsigned char data)
{
    SRAM_DATA_PORT = data;
}

inline unsigned char getDataLines()
{
    return SRAM_DATA_PORT;
}

inline void setAddressLines(unsigned long int addr)
{
    SRAM_ADDR_0 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_1 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_2 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_3 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_4 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_5 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_6 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_7 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_8 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_9 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_10 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_11 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_12 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_13 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_14 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_15 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_16 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_17 = addr & 0x01;
    addr >>= 1;
    SRAM_ADDR_18 = addr & 0x01;
}

unsigned char SRAM_Read(unsigned long int addr)
{
    unsigned char data;
    SRAM_CE = 1;
    SRAM_OE = 1;
    SRAM_WE = 1;
    SRAM_DATA_TRIS = 0xFF;
    setAddressLines(addr);
    SRAM_CE = 0;
    SRAM_OE = 0;
    data = getDataLines();
    SRAM_OE = 1;
    SRAM_CE = 1;
    return data;
}

void SRAM_Write(unsigned long int addr, unsigned char data)
{
    SRAM_CE = 1;
    SRAM_WE = 1;
    SRAM_OE = 1;
    setAddressLines(addr);
    SRAM_CE = 0;
    SRAM_WE = 0;
    SRAM_DATA_TRIS = 0x00;
    setDataLines(data);
    SRAM_WE = 1;
    SRAM_CE = 1;
    SRAM_DATA_TRIS = 0xFF; // back to inputs just incase
}

void SRAM_Print(unsigned int addr, unsigned int count)
{
    unsigned char numBlanks = addr % SRAM_PRINT_ROW_CNT;

    if(numBlanks)
    {
        printf("\r\n[0x%.4x]  ", addr - numBlanks);
        for(; numBlanks > 0; numBlanks--)
            printf(".. ");
    }

    for(; count > 0; count--)
    {
        if(!(addr % SRAM_PRINT_ROW_CNT))
            printf("\r\n[0x%.4x]  ", addr);
        printf("%.2x ", SRAM_Read(addr++));
    }
    printf("\r\n");
}

void SRAM_Clear()
{
    unsigned int i = 0xffff;
    for(; i > 0; i--)
        SRAM_Write(i, 0);
}
