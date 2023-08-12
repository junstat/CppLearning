#include <vector>

using namespace std;

class Solution {
public:
    int m, n;

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (check(x, y) && matrix[x][y] != target) {
            if (matrix[x][y] > target) y--;
            else x++;
        }
        return check(x, y) && matrix[x][y] == target;
    }

    bool check(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};