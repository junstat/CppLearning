#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> dp(triangle.size() + 1, 0);
        for (int i = static_cast<int>(triangle.size() - 1); i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};