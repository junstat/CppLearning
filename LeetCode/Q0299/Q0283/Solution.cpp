#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        if (nums.empty()) return;
        int i = 0;
        for (const auto &n: nums)
            if (n != 0) nums[i++] = n;
        while (i < nums.size()) nums[i++] = 0;
    }
};