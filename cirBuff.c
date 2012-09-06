#include "cirBuff.h"

inline void cirBufferInit(cir_buff_t* cBuff, char *dataBuffer, unsigned int size)
{
    cBuff->buffer = dataBuffer;
    cBuff->size = size;
    cBuff->count = 0;
    cBuff->head = 0;
    cBuff->tail = 0;
}

inline cir_buff_status_t cirBufferAdd(cir_buff_t *cBuff, char data)
{
	cir_buff_status_t retVal = BUFFER_STATUS_SUCCESS;

	if(cBuff->count != cBuff->size)
	{
		cBuff->buffer[cBuff->tail] = data;
                cBuff->tail++;
                if(cBuff->tail == cBuff->size)
                    cBuff->tail = 0;
		cBuff->count++;
	}
	else
	{
		cBuff->stats.overflow++;
		retVal = BUFFER_STATUS_OVERFLOW;
	}
	return retVal;
}

inline cir_buff_status_t cirBufferRemove(cir_buff_t *cBuff, char *data)
{
	cir_buff_status_t retVal = BUFFER_STATUS_SUCCESS;

	if(0 < cBuff->count)
	{
		*data = cBuff->buffer[cBuff->head];
                cBuff->head++;
                if(cBuff->head == cBuff->size)
                    cBuff->head = 0;
		cBuff->count--;
	}
	else
	{
		cBuff->stats.underflow++;
		retVal = BUFFER_STATUS_UNDERFLOW;
	}
	return retVal;
}
