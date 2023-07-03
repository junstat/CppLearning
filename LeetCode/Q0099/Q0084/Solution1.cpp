#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int len = heights.size();
        int ans = 0;
        for (int cur = 0; cur < len; cur++) {   // 枚举高
            int height = heights[cur];
            int left = cur, right = cur;
            while (left - 1 >= 0 && heights[left - 1] >= height) {
                --left;
            }
            while (right + 1 < len && heights[right + 1] >= height) {
                ++right;
            }
            ans = max(ans, (right - left + 1) * height);
        }
        return ans;
    }
};