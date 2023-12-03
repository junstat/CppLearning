#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> r(m, 0), c(n, 0);
        unordered_map<int, vector<int>> matMap;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) matMap[mat[i][j]] = {i, j};
        for (int i = 0; i < arr.size(); ++i) {
            auto coord = matMap[arr[i]];
            int x = coord[0], y = coord[1];
            r[x]++;
            c[y]++;
            if (r[x] == n || c[y] == m) return i;
        };
        return arr.size() - 1;
    }

};