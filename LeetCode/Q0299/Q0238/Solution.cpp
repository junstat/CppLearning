#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 1, product = 1; i <= n; ++i) {
            ans[i - 1] = product;
            product *= nums[i - 1];
        }

        for (int i = n, product = 1; i >= 1; --i) {
            ans[i - 1] *= product;
            product *= nums[i - 1];
        }
        return ans;
    }
};