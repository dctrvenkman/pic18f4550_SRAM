/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#include "htc_wrapper.h"
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "uart.h"

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* High-priority service */
void interrupt high_isr(void)
{

      /* This code stub shows general interrupt handling.  Note that these
      conditional statements are not handled within 3 seperate if blocks.
      Do not use a seperate if block for each interrupt flag to avoid run
      time errors. */

      PIR1 = 0; // Clear all interrupt flags
}

/* Low-priority interrupt routine */
void low_priority interrupt low_isr(void)
{
    /* This code stub shows general interrupt handling.  Note that these
    conditional statements are not handled within 3 seperate if blocks.
    Do not use a seperate if block for each interrupt flag to avoid run
    time errors. */

    /* Check interrupt flags */
    if(PIR1bits.RCIF)// UART receive
    {
        if(RCSTAbits.FERR)
        {
            volatile char data = RCREG; // Read RCREG to clear error
            PORTDbits.RD3 ^= 1;
        }
        else if(RCSTAbits.OERR)
        {
            RCSTAbits.CREN = 0; // Disable then enable to clear error
            RCSTAbits.CREN = 1;
            PORTDbits.RD2 ^= 1;
        }
        else
        {
            uartRecvISR();
        }
        PIR1bits.RCIF = 0; // Clear RX interrput flag
    }
    else if(PIR1bits.TXIF)// UART transmit
    {
        uartTxmitISR();
        PIR1bits.TXIF = 0; // Clear TX interrupt flag
    }
    else
    {
        PIR1 = 0; // Clear all interrupt flags
        //INTCONbits.GIEH = 1; // Enable high priority interrupts
        //INTCONbits.GIEL = 1; // Enable low priority interrupts
    }
}
