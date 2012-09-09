/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include "htc_wrapper.h"
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include <plib.h>

#include "user.h"
#include "EEPROM.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    unsigned char config, baudconfig;
    unsigned spbrg;
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */
    EEPROM_Setup_Pins();

    /* Initialize peripherals */
    CloseUSART();
    config = USART_TX_INT_OFF & USART_RX_INT_ON & USART_BRGH_HIGH & USART_CONT_RX &
            USART_EIGHT_BIT & USART_ASYNCH_MODE & USART_ADDEN_OFF;
    /* SPBRG based on 8MHz clk */
    //spbrg = 16;   //115200
    //spbrg = 34;   // 57600
    spbrg = 103;  // 19200 known working w/ 8MHz clock
    //spbrg = 207;  //  9600
    //spbrg = 832;  //  2400
    //spbrg = 1665;   //  1200
    /* SPBRG based on 48MHz clk */
    //spbrg = 103; //115200 48MHz
    OpenUSART(config, spbrg);
    baudconfig = BAUD_IDLE_CLK_LOW & BAUD_16_BIT_RATE & BAUD_WAKEUP_OFF & BAUD_AUTO_OFF;
    baudconfig &= ~0x20; // RX Not inverted
    baudUSART(baudconfig);

    PIR1bits.RCIF = 0; // Clear RX interrput flag
    PIE1bits.RCIE = 1; // Enable UART receive interrupts
    IPR1bits.RCIP = 0; // Set UART receive as low priority interrupt
    
    PIR1bits.TXIF = 0; // Clear TX interrupt flag
    PIE1bits.TXIE = 0; // Disable UART transmit interrupts
    IPR1bits.TXIP = 0; // Set UART transmit as low priority interrupt

    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */
    RCONbits.IPEN = 1;

    /* Enable interrupts */
    PIR1 = 0; // Clear peripheral interrupts
    INTCONbits.GIEH = 1; // Enable high priority interrupts
    INTCONbits.GIEL = 1; // Enable low priority interrupts
}
