#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        dfs(nums, ans, cur);
        return ans;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &cur) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
        } else {
            for (const auto &num: nums) {
                if (find(cur.begin(), cur.end(), num) == cur.end()) {
                    cur.push_back(num);
                    dfs(nums, ans, cur);
                    cur.pop_back();
                }
            }
        }
    }
};