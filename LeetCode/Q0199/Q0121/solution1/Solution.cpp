#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur = 0, maxSoFar = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};
