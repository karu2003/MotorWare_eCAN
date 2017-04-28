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
#define FIFO_s 32 // size

typedef struct _FIFO_Obj_ {
	volatile uint32_t buf[FIFO_s];
	volatile unsigned char tail;
	volatile unsigned char head;
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
 
#endif //FIFO__H
