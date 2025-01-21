#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        n = numCourses;
        edges = prerequisites;
        buildGraph();
        todo.resize(n, false);
        done.resize(n, false);
        for (int i = 0; i < n; ++i) {
            if (!done[i] && !acylic(i)) return false;
        }
        return true;
    }

    bool acylic(int node) {
        if (todo[node]) return false;
        if (done[node]) return true;
        todo[node] = true;
        done[node] = true;

        for (auto &v: g[node]) {
            if (!acylic(v)) return false;
        }
        todo[node] = false;
        return true;
    }

    void buildGraph() {
        g.resize(n, vector<int>());
        for (auto &e: edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
        }
    }

private:
    int n;
    vector<vector<int>> edges;
    vector<vector<int>> g;
    vector<bool> todo, done;
};