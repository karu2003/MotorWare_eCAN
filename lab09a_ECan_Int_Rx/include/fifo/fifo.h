#ifndef FIFO__H
#define FIFO__H

#include "sw/modules/types/src/types.h"
 
//size must be a power of two: 4,8,16,32...128
//To use this code for fifo with size 256 or more, 
//it is necessary to change the head and tail type from unsigned char to unsigned short

//#define FIFO( size )\
//struct {\
//    uint32_t buf[size];\
//    unsigned char tail;\
//    unsigned char head;\
//  }

#define ECAN_BUF_SIZE 16

typedef struct _MSG_t_ {
	uint32_t msgID; //ID of received message.
	uint16_t dataLength; //Number of bytes received.
	uint32_t dataL; //Bytes 0-3
	uint32_t dataH; //Bytes 4-7
} MSG_t;

typedef struct _FIFO_ID_Obj_ {
	MSG_t buf[ECAN_BUF_SIZE]; //ID of received message.
	uint16_t tail; //Where the data is read.
	uint16_t head; //Where the new data is inserted.
} FIFO_ID_Obj;

#define FIFO_s 32 // size

typedef struct _FIFO_Obj_ {
	uint32_t buf[FIFO_s];
	uint16_t tail;
	uint16_t head;
} FIFO_Obj;

 
//the number of elements in the queue
#define FIFO_COUNT(fifo)     ((fifo).head-(fifo).tail)
 
//size fifo
#define FIFO_SIZE(fifo)      ( sizeof((fifo).buf)/sizeof((fifo).buf[0]) )
 
//fifo is filled?
#define FIFO_IS_FULL(fifo)   (FIFO_COUNT(fifo)==FIFO_SIZE(fifo))
 
//fifo is empty?
#define FIFO_IS_EMPTY(fifo)  ((fifo).tail==(fifo).head)
 
//free space in fifo
#define FIFO_SPACE(fifo)     (FIFO_SIZE(fifo)-FIFO_COUNT(fifo))
 
//put an element in fifo
#define FIFO_PUSH(fifo, byte) \
  {\
    (fifo).buf[(fifo).head & (FIFO_SIZE(fifo)-1)]=byte;\
    (fifo).head++;\
  }
 
//take the first element of fifo
#define FIFO_FRONT(fifo) ((fifo).buf[(fifo).tail & (FIFO_SIZE(fifo)-1)])
 
//reduce the number of elements in the queue
#define FIFO_POP(fifo)   \
  {\
      (fifo).tail++; \
  }
 
//clear fifo
#define FIFO_FLUSH(fifo)   \
  {\
    (fifo).tail=0;\
    (fifo).head=0;\
  } 

static inline void FIFO_PUSH_ID(FIFO_ID_Obj *g_FIFO, uint32_t msgID, uint32_t dlc_t, uint32_t dataL_t, uint32_t dataH_t) {
	MSG_t msg;
	msg.msgID = msgID;
	msg.dataLength = dlc_t;
	msg.dataL = dataL_t;
	msg.dataH = dataH_t;
	FIFO_PUSH(*g_FIFO, msg);
}
 
#endif //FIFO__H
