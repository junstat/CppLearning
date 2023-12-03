#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int curEnd = 0, curFarthest = 0, steps = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            curFarthest = max(curFarthest, nums[i] + i);
            if (i == curEnd) {
                steps++;
                curEnd = curFarthest;
            }
            if (curEnd >= nums.size() - 1) break;
        }
        return steps;
    }
};