#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        return process(nums, 2);
    }

    int process(vector<int> &nums, int k) {
        int u = 0;
        for (const auto &x: nums) {
            if (u < k || nums[u - k] != x) nums[u++] = x;
        }
        return u;
    }
};