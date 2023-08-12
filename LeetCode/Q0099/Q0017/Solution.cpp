#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string cur;
        dfs(digits, ans, cur, pad, 0);
        return ans;
    }

    void dfs(string digits, vector<string> &ans, string &cur, vector<string> &pad, int index) {
        if (index == digits.size()) {
            ans.push_back(cur);
            return;
        }
        string value = pad[digits[index] - '0'];
        for (char i : value) {
            cur.push_back(i);
            dfs(digits, ans, cur, pad, index + 1);
            cur.pop_back();
        }
    }
};