#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        circle(0, 0, n - 1, n - 1, 1, ans);
        return ans;
    }

    void circle(int x1, int y1, int x2, int y2, int start, vector<vector<int>> &ans) {
        if (x2 < x1 || y2 < y1) return;
        if (x1 == x2) {
            ans[x1][y1] = start;
            return;
        }
        int val = start;
        for (int i = y1; i < y2; i++) ans[x1][i] = val++;
        for (int i = x1; i < x2; i++) ans[i][y2] = val++;
        for (int i = y2; i > y1; i--) ans[x2][i] = val++;
        for (int i = x2; i > x1; i--) ans[i][y1] = val++;
        circle(x1 + 1, y1 + 1, x2 - 1, y2 - 1, val, ans);
    }
};