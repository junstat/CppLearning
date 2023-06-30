#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size(), buy = INT_MIN;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            buy = max(buy, dp[i] - prices[i]);
            dp[i + 1] = max(dp[i], prices[i] - fee + buy);
        }
        return dp[n];
    }
};