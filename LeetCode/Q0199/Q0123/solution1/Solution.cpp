#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for (int k = 1; k <= 2; ++k) {
            int mn = prices[0];
            for (int i = 1; i < n; ++i) {
                mn = min(mn, prices[i] - dp[k - 1][i - 1]);
                dp[k][i] = max(dp[k][i - 1], prices[i] - mn);
            }
        }
        return dp[2][n - 1];
    }
};