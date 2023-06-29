#include <vector>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int> &nums) {
        int ans = 2, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < n; ++j) {
                auto d = nums[j] - nums[i] + 1000;
                ans = max(ans, dp[j][d] = max(2, dp[i][d] + 1));
            }
        }
        return ans;
    }
};