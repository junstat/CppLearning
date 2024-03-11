#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, nums, 0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &cur, vector<int> &nums, int start) {
        ans.push_back(cur);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            dfs(ans, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};