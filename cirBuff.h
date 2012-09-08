#ifndef __CIRCULAR_BUFFER__
#define __CIRCULAR_BUFFER__

typedef enum
{
	BUFFER_STATUS_SUCCESS,
	BUFFER_STATUS_FAIL,
	BUFFER_STATUS_OVERFLOW,
	BUFFER_STATUS_UNDERFLOW
}cir_buff_status_t;

typedef struct
{
	unsigned int overflow;
	unsigned int underflow;
}cir_buff_stats_t;

typedef struct
{
	unsigned int size;
	unsigned int count;
	unsigned int head;
	unsigned int tail;
	cir_buff_stats_t stats;
	char *buffer;
}cir_buff_t;

#define CIR_BUFFER_INIT(buffer, bufferSize) {bufferSize, 0, 0, 0, {0, 0}, buffer}

inline void cirBufferInit(cir_buff_t* cBuff, char *dataBuffer, unsigned int size);
inline cir_buff_status_t cirBufferAdd(cir_buff_t* cBuff, char data);
inline cir_buff_status_t cirBufferRemove(cir_buff_t* cBuff, char *data);

#endif
