#include <vector>

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        vector<bool> seen(n, false);
        vector<vector<int>> g(n);
        for (auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        for (const auto &item: restricted) seen[item] = true;
        int ans = 0;
        dfs(0, g, ans, seen);
        return ans;
    }

    void dfs(int u, vector<vector<int>> &g, int &ans, vector<bool> &seen) {
        seen[u] = true;
        ans++;
        for (int v: g[u]) {
            if (!seen[v]) {
                dfs(v, g, ans, seen);
            }
        }
    }
};