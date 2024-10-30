#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, p = n - 1;
                while (k < p) {
                    while (k > j + 1 && k < n && nums[k] == nums[k - 1])++k;
                    if (k >= p) break;
                    long sum = (long) nums[i] + nums[j] + nums[k] + nums[p];
                    if (sum == target) ans.push_back({nums[i], nums[j], nums[k++], nums[p]});
                    else if (sum > target) p--;
                    else ++k;
                }
            }
        }
        return ans;
    }
};