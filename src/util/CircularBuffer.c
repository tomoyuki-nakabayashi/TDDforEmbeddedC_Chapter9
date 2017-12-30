#include "CircularBuffer.h"
#include "Utils.h"
#include <stdlib.h>

typedef struct CircularBufferStruct
{
  int *values;
} CircularBufferStruct;

CircularBuffer CircularBuffer_Create(int capacity)
{
  CircularBuffer self = calloc(1, sizeof(CircularBufferStruct));
  return self;
}

void CircularBuffer_Destroy(CircularBuffer self)
{
  if(self == NULL) return;

  free(self);
  self = NULL;
}

void CircularBuffer_Print(CircularBuffer self)
{
  FormatOutput("Circular buffer content:\n");
  FormatOutput("<>\n");
}