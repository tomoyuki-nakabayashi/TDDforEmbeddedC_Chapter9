#include "gtest/gtest.h"
extern "C" {
  #include "util/CircularBuffer.h"
  #include "mocks/FormatOutputSpy.h"
}

namespace circular_buffer_print_test {
  class CircularBufferPrintTest : public ::testing::Test
  {
    virtual void SetUp()
    {
      savedFormatOutput = FormatOutput;
      FormatOutput = FormatOutputSpy;
      FormatOutputSpy_Create(100);
      actualOutput = FormatOutputSpy_GetOutput();
      buffer = CircularBuffer_Create(10);
    }
    virtual void TearDown()
    {
      FormatOutput = savedFormatOutput;
      CircularBuffer_Destroy(buffer);
      FormatOutputSpy_Destroy();
    }
    protected:
      int (*savedFormatOutput)(const char* format, ...);
      CircularBuffer buffer;
      const char *actualOutput;
  };

  TEST_F(CircularBufferPrintTest, PrintEmpty)
  {
    const char *expectedOutput = "Circular buffer content:\n<>\n";
    CircularBuffer_Print(buffer);
    EXPECT_STREQ(expectedOutput, actualOutput);
  }

  TEST_F(CircularBufferPrintTest, PrintAfterOneIsPut)
  {
    const char *expectedOutput = "Circular buffer content:\n<17>\n";
    CircularBuffer_Put(buffer, 17);
    CircularBuffer_Print(buffer);
    EXPECT_STREQ(expectedOutput, actualOutput);
  }

  TEST_F(CircularBufferPrintTest, PrintNotYetWrapperOrFull)
  {
    const char *expectedOutput = "Circular buffer content:\n<10, 20, 30>\n";
    CircularBuffer_Put(buffer, 10);
    CircularBuffer_Put(buffer, 20);
    CircularBuffer_Put(buffer, 30);
    CircularBuffer_Print(buffer);
    EXPECT_STREQ(expectedOutput, actualOutput);
  }
} // namespace