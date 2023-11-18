#include <vector>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &nums) {
        int ans = -1, dMap[82] = {};
        for (const auto &n: nums) {
            int d = 0;
            for (int nn = n; nn; nn /= 10)
                d += nn % 10;
            if (dMap[d]) ans = max(ans, dMap[d] + n);
            dMap[d] = max(dMap[d], n);
        }
        return ans;
    }
};