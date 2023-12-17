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

int main() {
    vector<vector<int>> intervals = {{2, 3},
                                     {2, 2},
                                     {3, 3},
                                     {1, 3},
                                     {5, 7},
                                     {2, 2},
                                     {4, 6}};
    Solution s;
    s.merge(intervals);

}