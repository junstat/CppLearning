#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 边界处理
                if (i == 0 && j > 0) f[i][j] = f[i][j - 1] + grid[i][j];
                else if (j == 0 && i > 0) f[i][j] = f[i - 1][j] + grid[i][j];
                else if (i > 0) f[i][j] = min(f[i][j - 1], f[i - 1][j]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
};