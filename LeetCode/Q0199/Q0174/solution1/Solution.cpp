#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) {
            return 0;
        }
        int m = static_cast<int>(dungeon.size());
        int n = static_cast<int>(dungeon[0].size());
        vector<vector<int>> health(m, vector<int>(n, 0));
        health[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
        for (int i = m - 2; i >= 0; i--) {
            health[i][n - 1] = max(1, health[i + 1][n - 1] - dungeon[i][n - 1]);
        }
        for (int j = n - 2; j >= 0; j--) {
            health[m - 1][j] = max(1, health[m - 1][j + 1] - dungeon[m - 1][j]);
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                health[i][j] = max(1, min(health[i + 1][j], health[i][j + 1]) - dungeon[i][j]);
            }
        }
        return health[0][0];
    }
};