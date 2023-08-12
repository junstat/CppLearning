#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;
        vector<string> ans(n, "");
        int cur = 0;
        bool goDown = true;
        for (char c : s) {
            ans[cur] += c;
            if (cur == 0 || cur == (n - 1)) goDown = !goDown;
            cur += goDown ? -1 : 1;
        }
        for (int i = 1; i < n; ++i) ans[0] += ans[i];
        return ans[0];
    }
};