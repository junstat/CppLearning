#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        if (target == 0) return 1;
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        dfs(nums, target, dp);
        return dp[target];
    }

    int dfs(vector<int> &nums, int target, vector<int> &dp) {
        if (dp[target] != -1) return dp[target];

        int ans = 0;
        for (int i: nums) {
            if (i <= target) ans += dfs(nums, target - i, dp);
        }
        dp[target] = ans;
        return ans;
    }
};