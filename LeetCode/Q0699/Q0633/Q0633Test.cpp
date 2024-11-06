#include <gtest/gtest.h>
#include "Solution.cpp"

TEST(Q0633, Test1) {
    Solution s;
    auto val1 = s.judgeSquareSum(5);
    ASSERT_EQ(val1, true);

    auto val2 = s.judgeSquareSum(3);
    ASSERT_EQ(val2, false);

    auto val3 = s.judgeSquareSum(4);
    ASSERT_EQ(val3, true);
}