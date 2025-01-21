#include <vector>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        int cur = 0;
        if (len < 10) return {};

        set<int> seen;
        set<string> repeated;
        unordered_map<char, int> mp = {{'A', 0},
                                       {'C', 1},
                                       {'G', 2},
                                       {'T', 3}};
        for (int i = 0; i < 9; i++) {
            cur = (cur << 2) | mp[s[i]];
        }
        for (int i = 9; i < len; i++) {
            cur = ((cur << 2) | mp[s[i]]) & 0xfffff;
            if (seen.count(cur)) {
                repeated.insert(s.substr(i - 9, 10));
            } else {
                seen.insert(cur);
            }
        }
        vector<string> ans(repeated.begin(), repeated.end());
        return ans;
    }
};