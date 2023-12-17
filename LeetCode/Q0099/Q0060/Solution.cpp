#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> nums(n);
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
            nums[i - 1] = i;
        }
        for (int i = 0, l = k - 1; i < n; i++) {
            fact /= (n - i);
            int idx = l / fact;
            ans.push_back(nums[idx] + '0');
            nums.erase(nums.begin() + idx);
            l -= idx * fact;
        }
        return ans;
    }
};