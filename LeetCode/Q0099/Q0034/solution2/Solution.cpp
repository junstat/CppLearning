#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return {-1, -1};
        double left = target - 0.5, right = target + 0.5;
        int l = binarySearch(nums, left), r = binarySearch(nums, right);
        if (l == r) {
            return {-1, -1};
        } else {
            return {l, r - 1};
        }
    }

    static int binarySearch(vector<int> &nums, double target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (target > nums[m]) l = m + 1;
            else h = m - 1;
        }
        return l;
    }
};