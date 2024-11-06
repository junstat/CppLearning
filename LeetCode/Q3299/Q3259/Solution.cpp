#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<array<long long, 2>> f(n + 2);
        for (int i = 0; i < n; i++) {
            f[i + 2][0] = max(f[i + 1][0], f[i][1]) + a[i];
            f[i + 2][1] = max(f[i + 1][1], f[i][0]) + b[i];
        }
        return max(f[n + 1][0], f[n + 1][1]);
    }
};

