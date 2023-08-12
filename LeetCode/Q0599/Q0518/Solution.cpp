#include <vector>

using namespace std;

class Solution {
public:
    int change(int cnt, vector<int> &cs) {
        int n = cs.size();
        vector<int> f(cnt + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int val = cs[i - 1];
            for (int j = val; j <= cnt; ++j) {
                f[j] += f[j - val];
            }
        }
        return f[cnt];
    }
};