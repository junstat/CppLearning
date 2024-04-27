#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), cnt = count(s.begin(), s.end(), '1');
        string ans(n, '0');
        // 奇数，最后一位为1
        ans[n - 1] = '1';
        if (cnt == 1) return ans;
        for (int i = 0; i < cnt - 1; ++i)
            ans[i] = '1';
        return ans;
    }
};