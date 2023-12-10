#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<int>> graph(n);
        for (auto &c: connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(-c[0]);
        }
        return dfs(graph, vector<bool>(n) = {}, 0);
    }

    int dfs(vector<vector<int>> &graph, vector<bool> &seen, int from) {
        auto change = 0;
        seen[from] = true;
        for (auto &to: graph[from]) {
            if (!seen[abs(to)])
                change += dfs(graph, seen, abs(to)) + (to > 0);
        }
        return change;
    }
};