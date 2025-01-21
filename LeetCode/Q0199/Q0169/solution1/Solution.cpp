#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> count;
        for (int num: nums) {
            if (count[num] == 0) {
                count[num] = 1;
            } else {
                count[num] += 1;
            }
            if (count[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }
};