#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        n = numCourses;
        edges = prerequisites;
        buildGraph();
        computeInDegrees();
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (degrees[j] == 0) break;
            }
            if (j == n) return false;
            degrees[j]--;
            for (auto &v: g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }

    void buildGraph() {
        g.resize(n, vector<int>());
        for (auto &e: edges) {
            g[e[1]].push_back(e[0]);
        }
    }

    void computeInDegrees() {
        degrees.resize(g.size(), 0);
        for (auto &adj: g) {
            for (auto &v: adj) {
                degrees[v]++;
            }
        }
    }

private:
    vector<vector<int>> g;
    vector<int> degrees;
    int n;
    vector<vector<int>> edges;
};