#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        size_t n = nums.size();
        vector<string> ss(n);
        for (size_t i = 0; i < n; i++) {
            ss[i] = to_string(nums[i]);
        }
        sort(ss.begin(), ss.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        string ans;
        for (const auto &s: ss) {
            ans += s;
        }
        size_t len = ans.size();
        size_t k = 0;
        while (k < len - 1 && ans[k] == '0') {
            k++;
        }
        return ans.substr(k);
    }
};
