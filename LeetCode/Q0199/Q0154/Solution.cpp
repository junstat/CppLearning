#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        size_t n = nums.size();
        size_t l = 0;
        size_t r = n - 1;
        while (l < r && nums[0] == nums[r]) {
            --r;
        }
        while (l < r) {
            size_t mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return r + 1 < n ? nums[r + 1] : nums[0];
    }
};