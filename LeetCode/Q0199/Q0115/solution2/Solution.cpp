#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        size_t n = s.size(), m = t.size();
        vector<int32_t> cur(m + 1, 0);
        cur[0] = 1;
        for (size_t j = 1; j <= n; ++j) {
            int32_t pre = 1;
            for (size_t i = 1; i <= m; ++i) {
                int32_t tmp = cur[i] % MOD;
                cur[i] = cur[i] % MOD + (t[i - 1] == s[j - 1] ? pre : 0);
                pre = tmp;
            }
        }
        return cur[m];
    }

    const int32_t MOD = 1e9 + 7;
};