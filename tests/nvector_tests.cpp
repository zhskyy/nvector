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
        nvector<int> y = nvector<int>();
        nvector<nvector<int>> yy = nvector<nvector<int>>();
    });
}

TEST(nvector, operator_eq_test_1)
{
    nvector<double> x1(5), x2(3);
    x1 = x2;

    //EXPECT_THROW(x1.at(4), std::range_error);
    EXPECT_EQ(x1.size(), 3);

}

TEST(nvector, operator_squre_bars_1)
{
    struct my_own_type {
      int x, y;
    };

    const nvector<my_own_type> x(2);

    const my_own_type expected_result = x[7L];
    EXPECT_EQ(expected_result, my_own_type());
}
