#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int prevMax = 0;
        int currMax = 0;
        for (int x: nums) {
            int temp = currMax;
            currMax = max(prevMax + x, currMax);
            prevMax = temp;
        }
        return currMax;
    }
};