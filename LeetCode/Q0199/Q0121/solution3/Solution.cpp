#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();
        int sell = 0, buy = -prices[0];
        for (size_t i = 1; i < n; ++i) {
            sell = max(sell, buy + prices[i]);
            buy = max(buy, -prices[i]);
        }
        return sell;
    }
};
