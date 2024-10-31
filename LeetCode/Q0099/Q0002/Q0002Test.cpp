#include "gtest/gtest.h"
#include "Solution.cpp"
#include <vector>

TEST(Q0002Test, example1) {
    std::vector<int> nums1 = {2, 4, 3};
    std::vector<int> nums2 = {5, 6, 4};
    Solution s;
    auto result = s.addTwoNumbers(createList(nums1), createList(nums2));
    ASSERT_NE(result, nullptr);
    fmt::println("example1:");
    printList(result);
}

TEST(Q0002Test, example2) {
    std::vector<int> nums1 = {0};
    std::vector<int> nums2 = {0};
    Solution s;
    auto result = s.addTwoNumbers(createList(nums1), createList(nums2));
    ASSERT_NE(result, nullptr);
    fmt::println("example2:");
    printList(result);
}

TEST(Q0002Test, example3) {
    std::vector<int> nums1 = {9, 9, 9, 9, 9, 9, 9};
    std::vector<int> nums2 = {9, 9, 9, 9};
    Solution s;
    auto result = s.addTwoNumbers(createList(nums1), createList(nums2));
    ASSERT_NE(result, nullptr);
    fmt::println("example3:");
    printList(result);
}
