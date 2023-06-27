#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &arr) {
        int n = arr.size(), ans = arr[0];
        vector<int> f(n), g(n);
        f[0] = arr[0], g[0] = -200001;
        for (int i = 1; i < n; ++i) {
            f[i] = max(f[i - 1] + arr[i], arr[i]);
            g[i] = max(g[i - 1] + arr[i], f[i - 1]);
            ans = max(ans, max(f[i], g[i]));
        }
        return ans;
    }
};