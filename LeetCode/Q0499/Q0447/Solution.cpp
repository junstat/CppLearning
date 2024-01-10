#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x = points[i][0] - points[j][0], y = points[i][1] - points[j][1];
                int d = x * x + y * y;
                mp[d]++;
            }
            for (auto [_, cnt]: mp) {
                ans += cnt * (cnt - 1);
            }
        }
        return ans;
    }
};