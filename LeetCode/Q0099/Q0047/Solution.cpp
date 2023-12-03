#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> seen(nums.size(), false);
        dfs(nums, ans, cur, seen);
        return ans;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &cur, vector<bool> &seen) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (seen[i] || i > 0 && nums[i] == nums[i - 1] && !seen[i - 1]) continue;
                seen[i] = true;
                cur.push_back(nums[i]);
                dfs(nums, ans, cur, seen);
                seen[i] = false;
                cur.pop_back();
            }
        }
    }
};