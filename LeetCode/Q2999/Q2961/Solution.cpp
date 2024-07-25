#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            auto &v = variables[i];
            if (pow(pow(v[0], v[1], 10), v[2], v[3]) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    int pow(int x, int n, int mod) {
        int res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
};