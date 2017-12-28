#include "FormatOutputSpy.h"

static char *output = NULL;

void FormatOutputSpy_Create(int len)
{
  output = malloc(len);
}

void FormatOutputSpy_Destroy(void)
{
  free(output);
}

char* FormatOutputSpy_GetOutput(void)
{
  return output;
}

int FormatOutputSpy(const char *format, ...)
{
  va_list list;
  va_start(list, fmt);
  int ret = vprintf(fmt, list);
  va_end(list);
  return ret;
}