#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        circle(0, 0, m - 1, n - 1, ans, matrix);
        return ans;
    }

    void circle(int x1, int y1, int x2, int y2, vector<int> &ans, vector<vector<int>> &mat) {
        if (x2 < x1 || y2 < y1) return;
        if (x1 == x2) {
            for (int i = y1; i <= y2; i++)ans.push_back(mat[x1][i]);
            return;
        }
        if (y1 == y2) {
            for (int i = x1; i <= x2; i++) ans.push_back(mat[i][y2]);
            return;
        }
        for (int i = y1; i < y2; i++) ans.push_back(mat[x1][i]);
        for (int i = x1; i < x2; i++) ans.push_back(mat[i][y2]);
        for (int i = y2; i > y1; i--) ans.push_back(mat[x2][i]);
        for (int i = x2; i > x1; i--) ans.push_back(mat[i][y1]);
        circle(x1 + 1, y1 + 1, x2 - 1, y2 - 1, ans, mat);
    }
};