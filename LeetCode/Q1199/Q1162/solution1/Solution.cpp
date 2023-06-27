#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &g) {
        int ans = -1;
        for (auto i = 0; i < g.size(); ++i) {
            for (auto j = 0; j < g[i].size(); ++j) {
                if (g[i][j] == 1) {
                    g[i][j] = 0;
                    dfs(g, i, j);
                }
            }
        }
        for (auto &row: g)
            for (int col: row)
                if (col > 1) ans = max(ans, col - 1);
        return ans;
    }

    void dfs(vector<vector<int>> &g, int i, int j, int dist = 1) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size()
            || (g[i][j] != 0 && g[i][j] <= dist))
            return;
        g[i][j] = dist;
        for (const auto &d: dirs) {
            auto dx = i + d[0], dy = j + d[1];
            dfs(g, dx, dy, dist + 1);
        }
    }

private:
    int dirs[4][2] = {
            {-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1}
    };
};