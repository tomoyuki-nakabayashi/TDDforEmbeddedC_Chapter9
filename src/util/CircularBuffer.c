#include "CircularBuffer.h"
#include "Utils.h"
#include <stdlib.h>

typedef struct CircularBufferStruct
{
  int *values;
  int count;
} CircularBufferStruct;

enum {BUFFER_GUARD = -1};

CircularBuffer CircularBuffer_Create(int capacity)
{
  CircularBuffer self = calloc(1, sizeof(CircularBufferStruct));
  self->values = calloc(capacity, sizeof(int));
  self->values[0] = BUFFER_GUARD;
  self->count = 0;
  return self;
}

void CircularBuffer_Destroy(CircularBuffer self)
{
  free(self->values);
  free(self);
}

void CircularBuffer_Print(CircularBuffer self)
{
  FormatOutput("Circular buffer content:\n<");
  for(int i=0; i<self->count; i++)
  {
    if(i != 0)
      FormatOutput(", ");
    
    FormatOutput("%d", self->values[i]);
  }
  FormatOutput(">\n");
}

void CircularBuffer_Put(CircularBuffer self, int value)
{
  if(self == NULL) return;
  if(self->values == NULL) return;

  self->values[self->count++] = value;
  self->values[self->count] = BUFFER_GUARD;
}