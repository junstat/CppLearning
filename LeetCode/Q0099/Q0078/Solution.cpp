#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(0, nums, cur, ans);
        return ans;
    }

    void dfs(int u, vector<int> &nums, vector<int> &cur, vector<vector<int>> &ans) {
        ans.push_back(cur);
        for (int i = u; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(i + 1, nums, cur, ans);
            cur.pop_back();
        }
    }
};