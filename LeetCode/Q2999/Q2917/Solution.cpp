#include <vector>

using namespace std;

class Solution {
public:
    int findKOr(vector<int> &nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int cnt = 0;
            for (const auto &x: nums) cnt += x >> i & 1;
            if (cnt >= k) ans |= 1 << i;
        }
        return ans;
    }
};