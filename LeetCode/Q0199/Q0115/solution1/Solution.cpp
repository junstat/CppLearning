#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        size_t n = s.size(), m = t.size();
        s.insert(0, " ");
        t.insert(0, " ");
        vector<vector<int32_t>> f(n + 1, vector<int32_t>(m + 1, 0));
        for (size_t i = 0; i <= n; ++i) f[i][0] = 1;
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                f[i][j] = f[i - 1][j] % MOD;
                if (s[i] == t[j]) f[i][j] += f[i - 1][j - 1] % MOD;
            }
        }
        return f[n][m];
    }

    const int32_t MOD = 1e9 + 7;
};