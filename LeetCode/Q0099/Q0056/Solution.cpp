#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (auto &cur: intervals) {
            if (ans.back()[1] < cur[0]) {
                ans.push_back(cur);
            } else {
                ans.back()[1] = max(ans.back()[1], cur[1]);
            }
        }
        return ans;
    }
};