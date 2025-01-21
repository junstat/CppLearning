#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        vector<int> bit(32, 0);
        for (int num: nums) {
            for (int i = 0; i < 32; i++) {
                if ((num >> (31 - i) & 1) == 1) {
                    bit[i]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            bit[i] = bit[i] > nums.size() / 2 ? 1 : 0;
            ans += bit[i] * (1 << (31 - i));
        }
        return ans;
    }
};