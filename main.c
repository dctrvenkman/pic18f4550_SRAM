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
#include "SRAM.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
cliParam_t sramWriteParams[] = {{"address", CLI_PARAM_TYPE_UINT}, {"data", CLI_PARAM_TYPE_UCHAR}};
cliParam_t sramPrintParams[] = {{"address", CLI_PARAM_TYPE_UINT}, {"count", CLI_PARAM_TYPE_UINT}};
cliParam_t sramWriteBytesParams[] = {{"address", CLI_PARAM_TYPE_UINT}, {"count", CLI_PARAM_TYPE_UINT}};
cliParam_t params[] = {{"value", CLI_PARAM_TYPE_UINT}};

void sramWriteCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int addr = atoi(params[0]);
    unsigned char data = atoi(params[1]);
    SRAM_Write(addr, data);
}

void sramPrintCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int addr = atol(params[0]);
    unsigned int count = atol(params[1]);
    SRAM_Print(addr, count);
}

void sramWriteBytesCbk(const char* cmdName, char** params, unsigned char numParams)
{
#define RX_INDICATOR_COUNT 512
    unsigned int addr = atol(params[0]);
    unsigned int numBytes = atol(params[1]);
    unsigned int currCnt = 0;

    while(currCnt < numBytes)
    {
        SRAM_Write(addr++, getchar());
        if(RX_INDICATOR_COUNT-1 == currCnt % RX_INDICATOR_COUNT)
            putch('.');
        currCnt++;
    }
    printf("Done\r\n");
}

#include "SRAM.h"
void testCbk(const char* cmdName, char** params, unsigned char numParams)
{
    SRAM_Clear();
}
void ceCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int val = atoi(params[0]) & 0xff;
    SRAM_CE = val;
}
void weCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int val = atoi(params[0]) & 0xff;
    SRAM_WE = val;
}
void oeCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int val = atoi(params[0]) & 0xff;
    SRAM_OE = val;
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
    CLI_REGISTER_CMD("md", sramPrintCbk, sramPrintParams);
    CLI_REGISTER_CMD("mw", sramWriteCbk, sramWriteParams);
    CLI_REGISTER_CMD("mm", sramWriteBytesCbk, sramWriteBytesParams);
    CLI_REGISTER_CMD("t", testCbk, 0);
    CLI_REGISTER_CMD("ce", ceCbk, params);
    CLI_REGISTER_CMD("we", weCbk, params);
    CLI_REGISTER_CMD("oe", oeCbk, params);
    CLI_REGISTER_CMD("d", dCbk, params);
    CLI_REGISTER_CMD("a", aCbk, params);


    //test();


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
