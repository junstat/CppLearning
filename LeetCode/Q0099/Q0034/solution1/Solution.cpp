#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans = {-1, -1};
        int n = nums.size();
        if (n == 0) return ans;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] == target) {
            ans[0] = l;
            l = 0;
            r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (nums[mid] <= target) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans[1] = l;
        }
        return ans;
    }
};