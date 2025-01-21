#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n < 2) {
            return 0;
        }
        int l = *min_element(nums.begin(), nums.end());
        int u = *max_element(nums.begin(), nums.end());
        int gap = max(1, (u - l) / (n - 1));
        int m = (u - l) / gap + 1;
        vector<int> bucketsMin(m, INT_MAX);
        vector<int> bucketsMax(m, INT_MIN);
        for (int num: nums) {
            int k = (num - l) / gap;
            bucketsMin[k] = min(bucketsMin[k], num);
            bucketsMax[k] = max(bucketsMax[k], num);
        }
        int i = 0;
        int j = 0;
        gap = bucketsMax[0] - bucketsMin[0];
        while (j < m) {
            j = i + 1;
            while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN) {
                j++;
            }
            if (j == m) break;
            gap = max(gap, bucketsMin[j] - bucketsMax[i]);
            i = j;
        }
        return gap;
    }
};