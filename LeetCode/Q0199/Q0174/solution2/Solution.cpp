#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        // corner case
        if (dungeon.empty() || dungeon[0].empty()) {
            return 0;
        }
        int m = static_cast<int>(dungeon.size());
        int n = static_cast<int>(dungeon[0].size());

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
                } else if (i == m - 1) {
                    dp[m - 1][j] = max(dp[m - 1][j + 1] - dungeon[m - 1][j], 1);
                } else if (j == n - 1) {
                    dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
                } else {
                    dp[i][j] = min(max(dp[i + 1][j] - dungeon[i][j], 1),
                                   max(dp[i][j + 1] - dungeon[i][j], 1));
                }
            }
        }
        return dp[0][0];
    }
};