#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> dict;
        for (const auto &item: wordDict) dict.insert(item);

        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                dp[i] = dp[j] && dict.find(s.substr(j, i - j)) != dict.end();
                if (dp[i]) break;
            }
        }
        return dp[s.size()];
    }
};