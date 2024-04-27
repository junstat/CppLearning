#include <vector>
#include <climits>
using namespace std;

class Graph {
    vector<vector<int>> g; // 邻接矩阵
public:
    Graph(int n, vector<vector<int>> &edges) : g(n, vector<int>(n, INT_MAX / 2)) {
        for (auto &e: edges) {
            g[e[0]][e[1]] = e[2]; // 添加一条边（题目保证没有重边）
        }
    }

    void addEdge(vector<int> e) {
        g[e[0]][e[1]] = e[2]; // 添加一条边（题目保证这条边之前不存在）
    }

    int shortestPath(int start, int end) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2), vis(n);
        dis[start] = 0;
        while (true) {
            int x = -1;
            for (int i = 0; i < n; i++) {
                if (!vis[i] && (x < 0 || dis[i] < dis[x])) {
                    x = i;
                }
            }
            if (x < 0 || dis[x] == INT_MAX / 2) { // 所有从 start 能到达的点都被更新了
                return -1;
            }
            if (x == end) { // 找到终点，提前退出
                return dis[x];
            }
            vis[x] = true; // 标记，在后续的循环中无需反复更新 x 到其余点的最短路长度
            for (int y = 0; y < n; y++) {
                dis[y] = min(dis[y], dis[x] + g[x][y]); // 更新最短路长度
            }
        }
    }
};
