#include <vector>

using namespace std;

class Solution {
    int m, n;
public:
    vector<int> pondSizes(vector<vector<int>> &land) {
        m = land.size(), n = land[0].size();
        vector<int> ans;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (land[i][j] == 0) ans.push_back(dfs(land, i, j));
        sort(ans.begin(), ans.end());
        return ans;
    }

    int dfs(vector<vector<int>> &land, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || land[x][y]) return 0;
        land[x][y] = 1;
        int ans = 1;
        for (auto i = x - 1; i <= x + 1; ++i)
            for (auto j = y - 1; j <= y + 1; ++j)
                ans += dfs(land, i, j);
        return ans;
    }
};