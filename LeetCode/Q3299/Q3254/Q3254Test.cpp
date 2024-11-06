#include <gtest/gtest.h>
#include "Solution.cpp"

TEST(Q3254Test, example1) {
    Solution s;
    auto nums = vector<int>{1, 2, 3, 4, 3, 2, 5};
    auto ans = s.resultsArray(nums, 3);
    auto expect = vector<int>{3, 4, -1, -1, -1};
    ASSERT_EQ(ans, expect);
}

TEST(Q3254Test, example2) {
    Solution s;
    auto nums = vector<int>{2, 2, 2, 2, 2};
    auto ans = s.resultsArray(nums, 4);
    auto expect = vector<int>{-1, -1};
    ASSERT_EQ(ans, expect);
}

TEST(Q3254Test, example3) {
    Solution s;
    auto nums = vector<int>{3, 2, 3, 2, 3, 2};
    auto ans = s.resultsArray(nums, 2);
    auto expect = vector<int>{-1, 3, -1, 3, -1};
    ASSERT_EQ(ans, expect);
}
