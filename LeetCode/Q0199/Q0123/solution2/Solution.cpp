#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        size_t n = prices.size();
        if (n == 0) return 0;
        vector<int> dp(3, 0);
        vector<int> mn(3, prices[0]);
        for (int i = 1; i < n; ++i) {
            for (int k = 1; k <= 2; ++k) {
                mn[k] = min(mn[k], prices[i] - dp[k - 1]);
                dp[k] = max(dp[k], prices[i] - mn[k]);
            }
        }
        return dp[2];
    }
};