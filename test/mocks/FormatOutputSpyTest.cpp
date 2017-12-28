#include "gtest/gtest.h"
extern "C" {
  #include "util/Utils.h"
  #include "FormatOutputSpy.h"
}

namespace format_output_spy_test {
  class FormatOutputSpy : public ::testing::Test
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

  TEST_F(FormatOutputSpy, HelloWorld)
  {
    FormatOutputSpy_Create(20);
    FormatOutput("Hello, World\n");
    EXPECT_STREQ("Hello, World\n", FormatOutputSpy_GetOutput());
  }
}