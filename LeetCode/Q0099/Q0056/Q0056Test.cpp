#include "gtest/gtest.h"
#include <vector>
#include "Solution.cpp"

using namespace std;

TEST(Q0056Test, example1) {
    vector<vector<int>> intervals = {{2, 3},
                                     {2, 2},
                                     {3, 3},
                                     {1, 3},
                                     {5, 7},
                                     {2, 2},
                                     {4, 6}};
    Solution s;
    s.merge(intervals);
}