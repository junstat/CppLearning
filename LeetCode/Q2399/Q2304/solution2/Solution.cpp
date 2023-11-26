#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        // i对应m, j对应n
        int m = grid.size();
        int n = grid[0].size();
        // dp[i][j]，表示移动到i行j列的最小花费
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化第一行
        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }
        // dp[i][j] = min{dp[i - 1]层的数值加上moveCost的最小值} + grid[i][j]
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int res = INT_MAX;
                for (int k = 0; k < n; k++) {
                    int val = grid[i - 1][k];
                    int temp = dp[i - 1][k] + moveCost[val][j];
                    res = min(res, temp);
                }
                dp[i][j] = res + grid[i][j];
            }
        }

        // 扫描最后一行，取最小值
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[m - 1][j]);
        }

        return ans;
    }
};