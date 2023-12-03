#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string pre = countAndSay(n - 1), ans;
        int cnt = 1;
        for (int i = 0; i < pre.size(); ++i) {
            if (pre[i] != pre[i + 1]) {
                ans.push_back(cnt + '0');
                ans.push_back(pre[i]);
                cnt = 1;
            } else cnt++;
        }
        return ans;
    }
};