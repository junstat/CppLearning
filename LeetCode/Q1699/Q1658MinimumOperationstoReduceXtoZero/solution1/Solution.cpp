#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;
        int ans = -1, left = 0, sum = 0, n = nums.size();
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum > target) sum -= nums[left++];
            if (sum == target) ans = max(ans, right - left + 1);
        }
        return ans < 0 ? -1 : n - ans;
    }
};