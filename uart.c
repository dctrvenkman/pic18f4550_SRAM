#include "htc_wrapper.h"
#include "uart.h"
#include "cirBuff.h"

char rxBuffer[UART_RX_BUFF_SIZE];
char txBuffer[UART_TX_BUFF_SIZE];

cir_buff_t txCirBuff = CIR_BUFFER_INIT(txBuffer, sizeof(txBuffer));
cir_buff_t rxCirBuff = CIR_BUFFER_INIT(rxBuffer, sizeof(rxBuffer));

inline void uartTxmitISR(void)
{
    if(0 < txCirBuff.count)
    {
        char data;
        cirBufferRemove(&txCirBuff, &data);
        TXREG = data;
    }
    else
        PIE1bits.TXIE = 0; // Disable UART transmit interrupts
}

inline void uartRecvISR(void)
{
    if(BUFFER_STATUS_OVERFLOW == cirBufferAdd(&rxCirBuff, RCREG))
    {
        //PORTDbits.RD2 ^= 1;
    }
}

unsigned int readUART(char* buffer, unsigned int count)
{
    unsigned int rxBytes = 0;
    while((rxBytes < count) && (BUFFER_STATUS_SUCCESS == cirBufferRemove(&rxCirBuff, &buffer[rxBytes]))) // must be short circuiting
        rxBytes++;
    return rxBytes;
}

void writeUART(char* buffer, unsigned int count)
{
    if(0 < count)
    {
        int i;
        for(i = 0; i < count; i++)
        {
            if(BUFFER_STATUS_OVERFLOW == cirBufferAdd(&txCirBuff, buffer[i]))
            {
                //PORTDbits.RD2 ^= 1;
            }
        }
        PIE1bits.TXIE = 1; // Enable UART transmit interrupts
    }
}

// To implement printf putch must be defined
void putch(char data)
{
#if 1
    while(!TXIF)
        continue;
    TXREG = data;
#else
    // Blocking loop
    while(BUFFER_STATUS_OVERFLOW == cirBufferAdd(&txCirBuff, data))
        ;
    PIE1bits.TXIE = 1; // Enable UART transmit interrupts
#endif
}

// To implement scanf getche must be defined
char getche()
{
    char retVal;
    // Blocking loop
    while(BUFFER_STATUS_SUCCESS != cirBufferRemove(&rxCirBuff, &retVal))
        ;
    return retVal;
}
