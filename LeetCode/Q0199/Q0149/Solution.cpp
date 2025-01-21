#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        size_t n = points.size();
        int ans = 1;
        for (size_t i = 0; i < n; ++i) {
            unordered_map<string, int> cnt;
            int maxCnt = 0;
            for (size_t j = i + 1; j < n; ++j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int a = x1 - x2;
                int b = y1 - y2;
                int k = gcd(a, b);
                string key = to_string(a / k) + "/" + to_string(b / k);
                cnt[key]++;
                maxCnt = max(maxCnt, cnt[key]);
            }
            ans = max(ans, maxCnt + 1);
        }
        return ans;

    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};