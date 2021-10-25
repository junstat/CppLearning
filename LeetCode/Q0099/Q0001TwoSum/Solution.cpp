#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> elemIndexMap;
        for (int i = 0; i < nums.size(); i++) {
            int otherPart = target - nums[i];
            if (elemIndexMap.find(otherPart) != elemIndexMap.end())
                return vector<int>{elemIndexMap[otherPart], i};
            elemIndexMap[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};