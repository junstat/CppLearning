#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &g) {
        int n = g.size();
        queue<pair<int, int>> q;
        unordered_map<int, int> map;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (g[i][j] == 1) {
                    q.push(make_pair(i, j));
                    map[i * n + j] = 0;
                }
            }
        }
        int ans = -1;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int dx = front.first, dy = front.second;
            int step = map[dx * n + dy];
            for (const auto &di: dirs) {
                int nx = dx + di[0], ny = dy + di[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (g[nx][ny] != 0) continue;
                g[nx][ny] = step + 1;
                q.push(make_pair(nx, ny));
                map[nx * n + ny] = step + 1;
                ans = max(ans, step + 1);
            }
        }
        return ans;
    }


private:
    int dirs[4][2] = {
            {-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1}
    };
};