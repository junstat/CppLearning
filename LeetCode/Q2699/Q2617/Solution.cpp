#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), f;
        using min_heap_t = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>;
        vector<min_heap_t> col_heaps(n); // 每一列的最小堆
        for (int i = 0; i < m; i++) {
            min_heap_t row_h; // 第 i 行的最小堆
            for (int j = 0; j < n; j++) {
                while (!row_h.empty() && row_h.top().second < j) { // 无法到达第 j 列
                    row_h.pop(); // 弹出无用数据
                }
                auto &col_h = col_heaps[j];
                while (!col_h.empty() && col_h.top().second < i) { // 无法到达第 i 行
                    col_h.pop(); // 弹出无用数据
                }

                f = i || j ? INT_MAX : 1; // 起点算 1 个格子
                if (!row_h.empty()) f = row_h.top().first + 1; // 从左边跳过来
                if (!col_h.empty()) f = min(f, col_h.top().first + 1); // 从上边跳过来

                int g = grid[i][j];
                if (g && f < INT_MAX) {
                    row_h.emplace(f, g + j); // 经过的格子数，向右最远能到达的列号
                    col_h.emplace(f, g + i); // 经过的格子数，向下最远能到达的行号
                }
            }
        }
        return f < INT_MAX ? f : -1; // 此时的 f 是在 (m-1, n-1) 处算出来的
    }
};
