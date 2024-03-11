#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        auto n = s.size(), m = p.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < m; ++i) cnt[p[i] - 'a']++;
        int a = 0;
        for (int i = 0; i < 26; ++i)
            if (cnt[i]) a++;
        for (int l = 0, r = 0, b = 0; r < n; ++r) {
            if (--cnt[s[r] - 'a'] == 0) b++;
            if (r - l + 1 > m && ++cnt[s[l++] - 'a'] == 1) b--;
            if (b == a) ans.push_back(l);
        }
        return ans;
    }
};