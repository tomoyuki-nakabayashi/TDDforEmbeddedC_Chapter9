#include "gtest/gtest.h"
extern "C" {
  #include "RandomMinute.h"
}

namespace random_minute_test{

  enum {BOUND=30};

  class RandomMinute : public ::testing::Test
  {
    virtual void SetUp()
    {
      RandomMinute_Create(BOUND);
      srand(1);
    }
    virtual void TearDown()
    {
    }
  protected:
    int minute;
    void AssertMinuteIsInRange(void)
    {
      if (minute < -BOUND || minute > BOUND)
      {
        FAIL() << "Minute out of range.";
      }
    }

  };

  TEST_F(RandomMinute, GetIsInRange)
  {
    for(int i=0; i<100; i++)
    {
      minute = RandomMinute_Get();
      AssertMinuteIsInRange();
    }
  }
} // namespace