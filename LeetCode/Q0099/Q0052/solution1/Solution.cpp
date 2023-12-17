#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n), diag(2 * n - 1), antiDiag(2 * n - 1);
        return solve(col, diag, antiDiag, 0);
    }

    int solve(vector<bool> &col, vector<bool> &diag, vector<bool> &antiDig, int row) {
        int n = col.size(), count = 0;
        if (row == n) return 1;
        for (int column = 0; column < n; column++)
            if (!col[column] && !diag[row + column] && !antiDig[row - column + n - 1]) {
                col[column] = diag[row + column] = antiDig[row - column + n - 1] = true;
                count += solve(col, diag, antiDig, row + 1);
                col[column] = diag[row + column] = antiDig[row - column + n - 1] = false;
            }
        return count;
    }
};