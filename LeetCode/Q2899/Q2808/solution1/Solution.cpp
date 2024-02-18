#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int> &nums) {
        unordered_map<int, vector<int>> posMap;
        for (int i = 0; i < nums.size(); ++i) {
            posMap[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto &[n, pos]: posMap) {
            pos.push_back(pos[0] + nums.size());
            int seconds = 0;
            for (int i = 1; i < pos.size(); ++i)
                seconds = max(seconds, (pos[i] - pos[i - 1]) / 2);
            ans = min(ans, seconds);
        }
        return ans;
    }
};