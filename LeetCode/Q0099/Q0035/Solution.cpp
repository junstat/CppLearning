#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int t) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= t) r = mid;
            else l = mid + 1;
        }
        return nums[r] >= t ? r : r + 1;
    }
};