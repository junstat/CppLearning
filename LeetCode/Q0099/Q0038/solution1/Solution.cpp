#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            string cur;
            int m = ans.size();
            for (int j = 0; j < m;) {
                int k = j + 1;
                while (k < m && ans[j] == ans[k])k++;
                int cnt = k - j;
                cur += to_string(cnt) + ans[j];
                j = k;
            }
            ans = cur;
        }
        return ans;
    }
};