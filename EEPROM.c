#include <stdio.h>
#include "htc_wrapper.h"
#include "system.h"
#include "EEPROM.h"

// Number of bytes printed per line for EEPROM_Print
#define EEPROM_PRINT_ROW_CNT    16
// Temporary storage for a whole page
unsigned char tmpPageData[EEPROM_PAGE_SIZE];

void EEPROM_Setup_Pins()
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
    //TRISB &= 0xFF;  //PORTB[0:7] inputs
    TRISB &= 0x00;  //PORTB[0:7] outputs
    TRISE &= 0xF8;  //PORTE[0:2] outputs

    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0x7;
}

inline void setDataLines(unsigned char data){ EEPROM_DATA_PORT = data; }

inline unsigned char getDataLines(){ return EEPROM_DATA_PORT; }

inline void setAddressLines(unsigned long int addr)
{
    EEPROM_ADDR_0 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_1 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_2 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_3 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_4 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_5 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_6 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_7 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_8 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_9 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_10 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_11 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_12 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_13 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_14 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_15 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_16 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_17 = addr & 0x01;
    addr >>= 1;
    EEPROM_ADDR_18 = addr & 0x01;
}

unsigned char EEPROM_Read(unsigned long int addr)
{
    unsigned char data;
    EEPROM_CE = 1;
    EEPROM_OE = 1;
    EEPROM_WE = 1;
    EEPROM_DATA_TRIS = 0xFF;
    setAddressLines(addr);
    EEPROM_CE = 0;
    EEPROM_OE = 0;
    data = getDataLines();
    EEPROM_CE = 1;
    EEPROM_OE = 1;
    return data;
}

// Data bus write by strobing WE line
void EEPROM_Write(unsigned long int addr, unsigned char data)
{
    EEPROM_CE = 1;
    EEPROM_WE = 1;
    EEPROM_OE = 1;
    EEPROM_DATA_TRIS = 0x00;
    EEPROM_CE = 0;
    setAddressLines(addr);
    setDataLines(data);
    EEPROM_WE = 0;
    EEPROM_WE = 1;
    EEPROM_CE = 1;
    EEPROM_DATA_TRIS = 0xFF; // back to inputs just incase
}

// Write single byte in flash page

#ifdef WRITE_WHOLE_PAGE
void EEPROM_Page_Write(unsigned long int addr, unsigned char data)
{
    unsigned int i;
    unsigned long int pageBaseAddr = ADDR_TO_PAGE_BASE_ADDR(addr);

    // Store existing page data
    for(i = 0; i < EEPROM_PAGE_SIZE; i++)
        tmpPageData[i] = EEPROM_Read(pageBaseAddr + i);

    // Update page data with the new value
    tmpPageData[addr - pageBaseAddr] = data;

    // Enter Page Write Cycle
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0xA0);

    // Write back updated page data
    for(i = 0; i < EEPROM_PAGE_SIZE; i++)
        EEPROM_Write(pageBaseAddr + i, tmpPageData[i]);
    
    __delay_us(200); //Tblco
    // TODO: Use one of the methods to determine if write has completed
    __delay_ms(10); //Twc
}
#else
void EEPROM_Write_Byte(unsigned long int addr, unsigned char data)
{
    // Enter Page Write Cycle
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0xA0);

    // Write data
    EEPROM_Write(addr, data);

    __delay_us(200); //Tblco
    // TODO: Use one of the methods to determine if write has completed
    __delay_ms(10); //Twc
}
#endif

// Write entire flash page
#ifdef WRITE_WHOLE_PAGE
void EEPROM_Write_Page(unsigned long int addr, unsigned char* data)
{
    unsigned int i;
    unsigned long int pageBaseAddr = ADDR_TO_PAGE_BASE_ADDR(addr);
    unsigned char tmpData1, tmpData2;

    // Enter Page Write Cycle
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0xA0);

    // Write page data
    for(i = 0; i < EEPROM_PAGE_SIZE; i++)
        EEPROM_Write(pageBaseAddr + i, data[i]);

    __delay_us(200); //Tblco

    do
    {
        // DATA# Polling for completion
        tmpData1 = EEPROM_Read(pageBaseAddr + i - 1);
        tmpData2 = EEPROM_Read(pageBaseAddr + i - 1);
    }while(tmpData1 != tmpData2);
}
#else
void EEPROM_Write_Page(unsigned long int addr, unsigned char* data)
{
    unsigned int i;
    
    // Write page data
    for(i = 0; i < EEPROM_PAGE_SIZE; i++)
        EEPROM_Write_Byte(addr + i, data[i]);
}
#endif

void EEPROM_Data_Protect_Disable()
{
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0x80);
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0x20);
    __delay_ms(10); //Twc
}

void EEPROM_Erase_Chip()
{
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0x80);
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0x10);
    __delay_ms(10);__delay_ms(10); //Tsce
}

void EEPROM_ID()
{
    //ID Entry
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0x90);

    //READ 0xBF 0x07 from addr 0x0000 and 0x0001 respectively

    //ID Exit
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0xF0);
}

void EEPROM_Print(unsigned int addr, unsigned int count)
{
    unsigned char numBlanks = addr % EEPROM_PRINT_ROW_CNT;

    if(numBlanks)
    {
        printf("\r\n[0x%.4x]  ", addr - numBlanks);
        for(; numBlanks > 0; numBlanks--)
            printf(".. ");
    }

    for(; count > 0; count--)
    {
        if(!(addr % EEPROM_PRINT_ROW_CNT))
            printf("\r\n[0x%.4x]  ", addr);
        printf("%.2x ", EEPROM_Read(addr++));
    }
    printf("\r\n");
}
