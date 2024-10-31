#include "gtest/gtest.h"
#include "Solution.cpp"

TEST(Q0001Test, example1) {
    Solution s;
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> expect = {0, 1};
    ASSERT_EQ(s.twoSum(nums, 9), expect);
}

TEST(Q0001Test, example2) {
    Solution s;
    std::vector<int> nums = {3, 2, 4};
    std::vector<int> expect = {1, 2};
    ASSERT_EQ(s.twoSum(nums, 6), expect);
}

TEST(Q0001Test, example3) {
    Solution s;
    std::vector<int> nums = {3, 3};
    std::vector<int> expect = {0, 1};
    ASSERT_EQ(s.twoSum(nums, 6), expect);
}
