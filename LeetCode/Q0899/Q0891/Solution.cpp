#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int sumSubseqWidths(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        long c = 1, ans = 0, mod = 1e9 + 7, n = nums.size();
        for (int i = 0; i < n; ++i, c = c * 2 % mod)
            ans = (ans + nums[i] * c - nums[n - i - 1] * c) % mod;
        return (ans + mod) % mod;
    }
};

