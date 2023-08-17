#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        int low = 0, hi = nums.size() - 1;
        while (low <= hi) {  // 执行二分查找
            int mid = low + (hi - low) / 2;
            if (nums[mid] == target) return mid;
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) hi = mid - 1;    // nums[low] <= target < nums[mid]
                else low = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[hi]) low = mid + 1;   // nums[mid] < target <= nums[high]
                else hi = mid - 1;
            }
        }
        return -1;
    }
};