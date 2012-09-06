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

cliParam_t sramReadBparams[] = {{"address", CLI_PARAM_TYPE_UINT}};

void sramReadBCbk(const char* cmdName, char** params, unsigned char numParams)
{
    long int p1 = atol(params[0]);
    printf("Read 0x%x\n", SRAM_Read(p1));
}


cliParam_t sramWriteBparams[] = {/*{"address", CLI_PARAM_TYPE_UINT},*/ {"data", CLI_PARAM_TYPE_UCHAR}};

void sramWriteBCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned char p1 = (unsigned char)atoi(params[0]);
    SRAM_CE = p1;
}

void testCbk(const char* cmdName, char** params, unsigned char numParams)
{
    SRAM_OE ^= SRAM_OE;
}

cliParam_t sramPrintparams[] = {{"address", CLI_PARAM_TYPE_UINT}, {"count", CLI_PARAM_TYPE_UINT}};

void sramPrintCbk(const char* cmdName, char** params, unsigned char numParams)
{
    unsigned int p1 = atol(params[0]);
    unsigned int p2 = atol(params[1]);
    SRAM_Print(p1, p2);
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

    CLI_REGISTER_CMD("md", sramPrintCbk, sramPrintparams);
    CLI_REGISTER_CMD("t", testCbk, 0);
    CLI_REGISTER_CMD("r", sramReadBCbk, sramReadBparams);
    CLI_REGISTER_CMD("w", sramWriteBCbk, sramWriteBparams);

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
