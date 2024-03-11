#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i], b = target - a;
            if (mp.find(b) != mp.end())
                return {mp[b], i};
            mp[a] = i;
        }
        return {-1, -1};
    }
};