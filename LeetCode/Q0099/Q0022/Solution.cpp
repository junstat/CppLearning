#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ans;
    int mx, len;

    vector<string> generateParenthesis(int n) {
        mx = n;
        len = 2 * n;
        dfs(0, 0, "");
        return ans;
    }

    void dfs(int i, int score, string path) {
        if (i == len) {
            if (score == 0) ans.push_back(path);
        } else {
            if (score + 1 <= mx) dfs(i + 1, score + 1, path + "(");
            if (score - 1 >= 0) dfs(i + 1, score - 1, path + ")");
        }
    }
};