#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> cur;
        vector<string> ans;
        dfs(s, 0, s.size(), cur, ans);
        return ans;
    }

    void dfs(const string &s, int idx, int n, vector<int> &cur, vector<string> &ans) {
        if (cur.size() > 4) return;
        if (idx == n) {
            if (cur.size() == 4) {
                string addr;
                for (int i = 0; i < 4; ++i) {
                    addr += to_string(cur[i]);
                    addr += ".";
                }
                ans.push_back(addr.substr(0, addr.size() - 1));
            }
        } else {
            for (int i = idx; i < n; ++i) {
                int t = 0;
                for (int j = idx; j <= i; ++j) t = t * 10 + (s[j] - '0');
                if (s[idx] == '0' && i != idx) break;
                if (t > 255) break;
                cur.push_back(t);
                dfs(s, i + 1, n, cur, ans);
                cur.pop_back();
            }
        }
    }
};