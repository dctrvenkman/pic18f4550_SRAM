#ifndef __UART__
#define __UART__

#define UART_TX_BUFF_SIZE 128 // 128 byte transmit buffer
#define UART_RX_BUFF_SIZE 256 // 256 byte receive buffer

inline void uartTxmitISR(void);
inline void uartRecvISR(void);

unsigned int readUART(char* buffer, unsigned int count);
void writeUART(char* buffer, unsigned int count);
#endif