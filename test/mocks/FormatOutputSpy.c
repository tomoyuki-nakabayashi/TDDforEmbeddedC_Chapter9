#include "FormatOutputSpy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *buffer = NULL;
static int buffer_size = 0;

void FormatOutputSpy_Create(int len)
{
  buffer_size = len+1;
  buffer = malloc(buffer_size);
  memset(buffer, '\0', buffer_size);
}

void FormatOutputSpy_Destroy(void)
{
  if(buffer == NULL) 
    return;

  free(buffer);
  buffer = NULL;
}

char* FormatOutputSpy_GetOutput(void)
{
  return buffer;
}

int FormatOutputSpy(const char *format, ...)
{
  va_list arguments;
  va_start(arguments, format);
  int written_size = vsnprintf(buffer, buffer_size, format, arguments);
  va_end(arguments);
  return written_size;
}