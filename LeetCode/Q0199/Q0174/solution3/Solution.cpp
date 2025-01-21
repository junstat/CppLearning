#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = static_cast<int>(dungeon.size()), n = static_cast<int>(dungeon[0].size());
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int health = 0;
                if (i == m - 1) health = dp[j + 1] - dungeon[i][j];
                else if (j == n - 1) health = dp[j] - dungeon[i][j];
                else health = min(dp[j + 1], dp[j]) - dungeon[i][j];
                dp[j] = health <= 0 ? 1 : health;
            }
        }
        return dp[0];
    }
};