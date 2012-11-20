/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <htc.h>            /* HiTech General Includes */

/******************************************************************************/
/* Configuration Bits                                                         */
/*                                                                            */
/* Refer to 'HI-TECH PICC and PICC18 Toolchains > PICC18 Configuration        */
/* Settings' under Help > Contents in MPLAB X IDE for available PIC18         */
/* Configuration Bit Settings for the correct macros when using the C18       */
/* compiler.  When using the Hi-Tech PICC18 compiler, refer to the compiler   */
/* manual.pdf in the compiler installation doc directory section on           */
/* 'Configuration Fuses'.  The device header file in the HiTech PICC18        */
/* compiler installation directory contains the available macros to be        */
/* embedded.                                                                  */
/*                                                                            */
/* For additional information about what the hardware configurations mean in  */
/* terms of device operation, refer to the device datasheet.                  */
/*                                                                            */
/* General C18 syntax for configuration macros:                               */
/* #pragma config <Macro Name>=<Setting>, <Macro Name>=<Setting>, ...         */
/*                                                                            */
/* General HiTech PICC18 syntax:                                              */
/* __CONFIG(n,x);                                                             */
/*                                                                            */
/* n is the config word number and x represents the anded macros from the     */
/* device header file in the PICC18 compiler installation include directory.  */
/*                                                                            */
/******************************************************************************/
// For internal 8MHz osc
#if 0
#pragma config CPUDIV = OSC1_PLL2
#pragma config PLLDIV = 1
#pragma config USBDIV = 1
#pragma config IESO = OFF //Disable osc switchover mode
#pragma config FOSC = INTOSC_EC
#endif

// For external 20MHz osc
#pragma config CPUDIV = OSC1_PLL2
#pragma config PLLDIV = 5
#pragma config USBDIV = 2
#pragma config IESO = OFF //Enable osc switchover mode
#pragma config FOSC = HS

#pragma config FCMEN = OFF //Fail-safe clk mon disable
#pragma config VREGEN = OFF //USB vreg disable
#pragma config BOR = OFF
#pragma config BORV = 0
#pragma config PWRT = OFF //Power up timer enable
#pragma config WDTPS = 1
#pragma config WDT = OFF //Watchdog timer
#pragma config CCP2MX = OFF
#pragma config PBADEN = OFF //PortB<4:0> digital IO
#pragma config LPT1OSC = OFF //Low power timer 1 osc enable

#pragma config MCLRE = ON //OFF = RE3 input pin enabled, MCLR disabled
#pragma config DEBUG = ON //RB6-7 dedicated to in circuit debug
#pragma config STVREN = ON //Stack full/overflow will reset
#pragma config ICPRT = OFF //In circuit prog port disabled

#pragma config XINST = OFF //Extended instr set
#pragma config LVP = OFF //ON = Single supply ICSP enabled
