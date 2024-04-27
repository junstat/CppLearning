#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<int> result;
        if (n == 1) {
            result.push_back(0);
            return result;
        }

        vector<set<int>> adj(n);
        for (const auto &edge: edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1)
                result.push_back(i);
        }

        while (n > 2) {
            n -= result.size();
            vector<int> curLeaves;
            for (const auto &i: result) {
                int j = *adj[i].begin();
                adj[j].erase(i);
                if (adj[j].size() == 1)
                    curLeaves.push_back(j);
            }
            result = curLeaves;
        }
        return result;
    }
};