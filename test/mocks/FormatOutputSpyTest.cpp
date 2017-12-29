#include "gtest/gtest.h"
extern "C" {
  #include "FormatOutputSpy.h"
}

namespace format_output_spy_test {
  class FormatOutputSpyTest : public ::testing::Test
  {
    virtual void SetUp()
    {
      savedFormatOutput = FormatOutput;
      FormatOutput = FormatOutputSpy;
    }
    virtual void TearDown()
    {
      FormatOutput = savedFormatOutput;
      FormatOutputSpy_Destroy();
    }
    protected:
      int (*savedFormatOutput)(const char* format, ...);
  };

  TEST_F(FormatOutputSpyTest, HelloWorld)
  {
    FormatOutputSpy_Create(20);
    FormatOutput("Hello, World\n");
    EXPECT_STREQ("Hello, World\n", FormatOutputSpy_GetOutput());
  }
}