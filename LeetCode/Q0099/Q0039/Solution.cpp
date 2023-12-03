#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(target, 0, ans, cur, candidates);
        return ans;
    }

    void dfs(int t, int u, vector<vector<int>> &ans, vector<int> &cur, vector<int> &nums) {
        if (t == 0) {
            ans.emplace_back(cur);
        }
        for (int i = u; i < nums.size() && t >= nums[i]; ++i) {
            cur.push_back(nums[i]);
            dfs(t - nums[i], i, ans, cur, nums);
            cur.pop_back();
        }
    }
};