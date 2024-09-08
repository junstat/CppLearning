#include <vector>
#include <algorithm>
#include <fmt/format.h>
#include <fmt/ranges.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) < abs(b); });
        vector<int> ans(nums.size(), 0);
        for (size_t i =0; i < nums.size(); ++i) {
            ans[i] = nums[i] * nums[i];
        }
        return ans;
    }
};
