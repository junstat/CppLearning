#include <vector>

using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        init();
        int len = getLen(n);
        int ans = 0, prev = 0;
        for (int i = len; i >= 0; --i) {
            int cur = (n >> i) & 1;
            if (cur == 1) ans += f[i + 1][0];
            if (cur == 1 && prev == 1) break;
            prev = cur;
            if (i == 0) ans++;
        }
        return ans;
    }

    void init() {
        N = 50;
        f.resize(N, vector<long>(2));
        f[1][0] = 1;
        f[1][1] = 2;
        for (int i = 1; i < N - 1; ++i) {
            f[i + 1][0] = f[i][1];
            f[i + 1][1] = f[i][0] + f[i][1];
        }
    }

    int getLen(int n) {
        for (int i = 31; i >= 0; --i) {
            if (n >> i & 1) return i;
        }
        return 0;
    }

private:
    int N;
    vector<vector<long>> f;
};