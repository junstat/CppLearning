#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
        int ans = 0, x2 = -1;
        for (auto& p: points) {
            if (p[0] > x2) {
                ans++;
                x2 = p[0] + w;
            }
        }
        return ans;
    }
};