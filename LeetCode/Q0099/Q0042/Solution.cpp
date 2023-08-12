#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size(), ans = 0;
        stack<int> s;
        for (int r = 0; r < n; ++r) {
            while (!s.empty() && height[r] > height[s.top()]) {
                auto cur = s.top();
                s.pop();
                if (s.empty()) continue;
                int l = s.top();
                int w = r - l +1 -2;
                int h = min(height[l], height[r]) - height[cur];
                ans += w * h;
            }
            s.push(r);
        }
        return ans;
    }
};