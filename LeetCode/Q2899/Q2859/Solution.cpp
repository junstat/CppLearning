#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            bitset<32> binI(i);
            ans += binI.count() == k ? nums[i] : 0;
        }
        return ans;
    }
};