#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> preSum(n + 10, 0);
        for (int i = 1; i <= n; ++i) preSum[i] = preSum[i - 1] + nums[i - 1];
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int t = preSum[i], d = t - k;
            ans += mp[d];
            mp[t]++;
        }
        return ans;
    }
};