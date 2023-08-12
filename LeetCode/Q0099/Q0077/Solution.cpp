#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, 1, n, k);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &cur, int start, int n, int k) {
        if (k == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i <= n - k + 1; ++i) {
            cur.push_back(i);
            dfs(ans, cur, i + 1, n, k - 1);
            cur.pop_back();
        }
    }
};