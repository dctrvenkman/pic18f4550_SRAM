/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include "htc_wrapper.h"
#include <stdint.h>     /* For uint8_t definition */
#include <stdbool.h>    /* For true/false definition */
#include <plib.h>       /* Peripheral Library */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "system.h"     /* System funct/params, like osc/peripheral config */
#include "user.h"       /* User funct/params, such as InitApp */
#include "cirBuff.h"    /* Circular Buffer */
#include "uart.h"
#include "cliParser.h"
#include "EEPROM.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
cliParam_t EEPROMWriteParams[] = {{"address", CLI_PARAM_TYPE_UINT}, {"data", CLI_PARAM_TYPE_UCHAR}};
cliParam_t EEPROMPrintParams[] = {{"address", CLI_PARAM_TYPE_UINT}, {"count", CLI_PARAM_TYPE_UINT}};
cliParam_t EEPROMWriteBytesParams[] = {{"address", CLI_PARAM_TYPE_UINT}, {"count", CLI_PARAM_TYPE_UINT}};
cliParam_t params[] = {{"value", CLI_PARAM_TYPE_UINT}};

void EEPROMWriteCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int addr = atoi(params[0]);
    unsigned char data = atoi(params[1]);
    EEPROM_Write_Byte(addr, data);
}

void EEPROMPrintCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int addr = atol(params[0]);
    unsigned int count = atol(params[1]);
    EEPROM_Print(addr, count);
}

void EEPROMWriteBytesCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int addr = atol(params[0]);
    unsigned int numBytes = atol(params[1]);
    unsigned int currCnt = 0;

    while(currCnt < numBytes)
    {
        EEPROM_Write_Byte(addr++, getchar());
        if(EEPROM_PAGE_SIZE-1 == currCnt % EEPROM_PAGE_SIZE)
            putch('.');
        currCnt++;
    }
    printf("Done\r\n");
}

unsigned char pageData[EEPROM_PAGE_SIZE];

void EEPROMFillCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int numBytes = atol(params[0]);
    unsigned int currCnt = 0;
    unsigned int i; // Use extra var so as not to have to calc currCnt % 128

    while(currCnt < numBytes)
    {
        for(i = 0; i < EEPROM_PAGE_SIZE; i++)
        {
            pageData[i] = getchar();
            currCnt++;
        }
        EEPROM_Write_Page(currCnt - 1, pageData);
        putch('.');
    }
    printf("Done\r\n");
}

void unprotectCbk(const char* cmdName, char** params, unsigned char numParams)
{
    EEPROM_Data_Protect_Disable();
}

void eraseCbk(const char* cmdName, char** params, unsigned char numParams)
{
    EEPROM_Erase_Chip();
}

#if 0 // Messes up scanf
unsigned long int hexDecStrToLong(char* str)
{
    unsigned long int val;
    if(str[0] == '0' && str[1] == 'x')
        sscanf(str, "0x%x", &val);
    else
        sscanf(str, "%ld", &val);
    return val;
}
#endif



void testCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned char addr = atoi(params[0]);
    unsigned char data = atoi(params[1]);

    // Enter Page Write Cycle
    EEPROM_Write(0x5555, 0xaa);
    EEPROM_Write(0x2aaa, 0x55);
    EEPROM_Write(0x5555, 0xA0);

    EEPROM_Write(addr, data);

    __delay_us(200); //Tblco
    // TODO: Use one of the methods to determine if write has completed
    __delay_ms(10); //Twc
}
#ifdef DEBUG
void ceCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int val = atoi(params[0]) & 0xff;
    EEPROM_CE = val;
}
void weCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int val = atoi(params[0]) & 0xff;
    EEPROM_WE = val;
}
void oeCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int val = atoi(params[0]) & 0xff;
    EEPROM_OE = val;
}
void dCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int val = atoi(params[0]) & 0xff;
    TRISB = 0;
    PORTB = val;
}
extern inline void setAddressLines(unsigned long int addr);
void aCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int val = atoi(params[0]) & 0xff;
    setAddressLines(val);
}

void cCbk(const char* cmdName, char** params, unsigned char numParams)
{
    PORTB = 0xff;
    //__delay_ms(1);
    PORTB = 0x00;
}

void crCbk(const char* cmdName, char** params, unsigned char numParams)
{
    while(true)
    {
        PORTB ^= PORTB;
    }
}
#endif

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
uint8_t main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    printf("\33[2J"); // Clear screen
    printf("\x1b[H"); // Home cursor
    printf("Console Initialized v1\r\n");
    cliInit();

    // CLI Command registration
    CLI_REGISTER_CMD("md", EEPROMPrintCbk, EEPROMPrintParams);
    CLI_REGISTER_CMD("mw", EEPROMWriteCbk, EEPROMWriteParams);
    CLI_REGISTER_CMD("mm", EEPROMWriteBytesCbk, EEPROMWriteBytesParams);
    CLI_REGISTER_CMD("mf", EEPROMFillCbk, params);
    CLI_REGISTER_CMD("unprotect", unprotectCbk, 0);
    CLI_REGISTER_CMD("erase", eraseCbk, 0);

    CLI_REGISTER_CMD("t", testCbk, EEPROMWriteParams);
#ifdef DEBUG
    CLI_REGISTER_CMD("t", testCbk, EEPROMWriteParams);
    CLI_REGISTER_CMD("t", testCbk, 0);
    CLI_REGISTER_CMD("ce", ceCbk, params);
    CLI_REGISTER_CMD("we", weCbk, params);
    CLI_REGISTER_CMD("oe", oeCbk, params);
    CLI_REGISTER_CMD("d", dCbk, params);
    CLI_REGISTER_CMD("a", aCbk, params);
    CLI_REGISTER_CMD("c", cCbk, 0);
    CLI_REGISTER_CMD("cr", crCbk, 0);
#endif

    // Application Loop
    while(1)
    {
        cliReturn_t ret = cliParseInputChar(getchar());

        switch(ret)
        {
            case CLI_RETURN_CMD_NOT_FOUND:
                printf("Invalid command\r\n");
                break;
            case CLI_RETURN_TOO_FEW_PARAMS:
                printf("Too few parameters\r\n");
                break;
            case CLI_RETURN_TOO_MANY_PARAMS:
                printf("Too many parameters\r\n");
        }

        if(CLI_RETURN_STILL_PARSING != ret)
            printf(">");
    }
    return 0; //unreachable
}
