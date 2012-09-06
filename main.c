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
cliParam_t sramPrintparams[] = {{"address", CLI_PARAM_TYPE_UINT}, {"count", CLI_PARAM_TYPE_UINT}};

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

void testCbk(const char* cmdName, char** params, unsigned char numParams)
{
    //Do Something
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
    CLI_REGISTER_CMD("md", sramPrintCbk, sramPrintparams);
    CLI_REGISTER_CMD("mw", sramWriteCbk, sramWriteParams);
    //CLI_REGISTER_CMD("t", testCbk, 0);

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
