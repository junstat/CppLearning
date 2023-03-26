#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        string ans;
        auto n = s.length();
        bool dp[n][n];
        int maxLen = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                dp[i][j] = s[i] == s[j] && ((j - i <= 2) || dp[i + 1][j - 1]);
                if (dp[i][j] && (j - i + 1 > maxLen)) {
                    maxLen = j - i + 1;
                    ans = s.substr(i, maxLen);
                }
            }
        }
        return ans;
    }
};