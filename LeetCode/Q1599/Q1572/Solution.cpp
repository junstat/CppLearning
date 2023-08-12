#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size();
        for (int i = 0; i < n; ++i) {
            ans += mat[i][i];
            ans += mat[n - 1 - i][i];
        }
        return n % 2 == 0 ? ans : ans - mat[n / 2][n / 2];
    }
};