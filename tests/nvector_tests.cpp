#include "../src/nvector.hpp"
#include <gtest/gtest.h>

TEST(base_test, chacking_test)
{
	ASSERT_EQ(0, 0) << "!";
}

TEST(nvector, constructor_test)
{
    EXPECT_NO_FATAL_FAILURE({
        nvector<double> x = nvector<double>();
    });
}
