#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = nums[0], cur = 0;
        for (const auto &num: nums) {
            cur = max(cur + num, num);
            ans = max(ans, cur);
        }
        return ans;
    }
};