#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.begin() + nums.size())) {
            ans.push_back(nums);
        }
        return ans;
    }
};