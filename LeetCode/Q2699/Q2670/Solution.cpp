#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int> &nums) {
        vector<int> ans;
        unordered_map<int, int> mp, rmp;
        for (const auto &n: nums) rmp[n]++;
        for (const auto &n: nums) {
            mp[n]++;
            rmp[n]--;
            if (rmp[n] == 0) rmp.erase(n);
            ans.push_back(mp.size() - rmp.size());
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = s.distinctDifferenceArray(nums);
    for (const auto &item: ans) cout << item << " ";
    cout << endl;
    return 0;
}