#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;
        for (const auto &chars: matrix) {
            for (int i = 0; i < n; ++i) {
                if (chars[i] == '1') heights[i]++;
                else heights[i] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> d;
        int ans = 0;
        for (int r = 0; r <= n; ++r) {
            int h = (r == n ? 0 : heights[r]);
            if (d.empty() || h >= heights[d.top()])d.push(r);
            else {
                int cur = d.top();
                d.pop();
                int l = d.empty() ? -1 : d.top();
                int w = r - l - 1;
                ans = max(ans, heights[cur] * w);
                r--;
            }
        }
        return ans;
    }
};