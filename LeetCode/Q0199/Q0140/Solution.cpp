#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet;
        for (string w: wordDict) {
            wordSet.insert(w);
        }
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        vector<vector<string>> record(n + 1);
        record[0] = {""};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string af = s.substr(j, i - j);
                if (dp[j] && wordSet.count(af)) {
                    dp[i] = true;
                    for (string x: record[j]) {
                        string news = (x.size() > 0 ? (x + " ") : "") + af;
                        record[i].push_back(news);
                    }
                }
            }
        }
        return record[n];
    }
};
