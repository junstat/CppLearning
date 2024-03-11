#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        return ways(s, 0, s.size() - 1);
    }

    int ways(const string &s, int l, int r) {
        if (mp.find(l) != mp.end()) return mp[l];
        if (l <= r && s[l] == '0') return 0;
        if (l >= r) return 1;

        int w = ways(s, l + 1, r);
        int prefix = (s[l] - '0') * 10 + (s[l + 1] - '0');
        if (prefix <= 26) w += ways(s, l + 2, r);

        return mp[l] = w;
    }

    unordered_map<int, int> mp;
};