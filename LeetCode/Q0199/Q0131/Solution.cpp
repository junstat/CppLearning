#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s, 0, ans, cur);
        return ans;
    }

    void dfs(const string &s, int pos, vector<vector<string>> &ans, vector<string> &cur) {
        if (pos == s.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = pos; i < s.size(); ++i) {
            if (isPalindrome(s, pos, i)) {
                cur.push_back(s.substr(pos, i - pos + 1));
                dfs(s, i + 1, ans, cur);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int lo, int hi) {
        while (lo < hi)
            if (s[lo++] != s[hi--]) return false;

        return true;
    }
};