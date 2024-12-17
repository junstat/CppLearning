#include <string>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.empty() || s.size() <= 1) {
            return 0;
        }

        size_t n = s.size();
        vector<int> dp(n);
        std::iota(dp.begin(), dp.end(), 0);
        for (int mid = 1; mid < n; ++mid) {
            for (int start = mid, end = mid; start >= 0 && end < n && s[start] == s[end]; --start, ++end) {
                int newCutAtEnd = (start == 0) ? 0 : dp[start - 1] + 1;
                dp[end] = min(dp[end], newCutAtEnd);
            }

            for (int start = mid - 1, end = mid; start >= 0 && end < n && s[start] == s[end]; --start, ++end) {
                int newCutAtEnd = (start == 0) ? 0 : dp[start - 1] + 1;
                dp[end] = min(dp[end], newCutAtEnd);
            }
        }
        return dp[n - 1];
    }
};


TEST(Q0132Test, example1) {
    Solution solution;
    EXPECT_EQ(solution.minCut("aab"), 1);
}
