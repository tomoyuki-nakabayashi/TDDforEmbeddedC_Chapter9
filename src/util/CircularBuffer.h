#ifndef SRC_UTIL_CIRCULAR_BUFFER_H_
#define SRC_UTIL_CIRCULAR_BUFFER_H_

typedef struct CircularBufferStruct * CircularBuffer;

CircularBuffer CircularBuffer_Create(int capacity);
void CircularBuffer_Destroy(CircularBuffer);
void CircularBuffer_Print(CircularBuffer);

#endif //SRC_UTIL_CIRCULAR_BUFFER_H_