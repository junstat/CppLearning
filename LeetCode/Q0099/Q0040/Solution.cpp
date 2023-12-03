#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(target, 0, ans, cur, candidates);
        return ans;
    }

    void dfs(int t, int u, vector<vector<int>> &ans, vector<int> &cur, vector<int> &cs) {
        if (t == 0) {
            ans.push_back(cur);
            return;
        } else if (t < 0) return;
        for (int i = u; i < cs.size(); ++i) {
            if (i != u && cs[i] == cs[i - 1]) continue;
            cur.push_back(cs[i]);
            dfs(t - cs[i], i + 1, ans, cur, cs);
            cur.pop_back();
        }
    }
};