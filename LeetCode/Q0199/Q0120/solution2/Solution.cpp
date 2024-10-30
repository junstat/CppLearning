#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        size_t n = triangle.size();
        dp.resize(n, vector<int>(n, -1));
        return dfs(triangle, 0, 0);
    }

    int dfs(vector<vector<int>> &triangle, int i, int j) {
        if (i == triangle.size()) {
            return 0;
        }
        if (dp[i][j] != INIT) {
            return dp[i][j];
        }
        return dp[i][j] = min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
    }

    vector<vector<int>> dp;
    static const int INIT = -1;
};
